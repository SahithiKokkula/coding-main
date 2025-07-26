import cv2
import numpy as np

def align_images(ref_img_gray, test_img_gray, max_features=500, good_match_percent=0.15):
    """
    Aligns the test_img_gray to ref_img_gray using ORB feature matching and homography.
    
    Returns:
        homography (np.ndarray): 3x3 Homography matrix.
    """
    orb = cv2.ORB_create(max_features)
    keypoints1, descriptors1 = orb.detectAndCompute(ref_img_gray, None)
    keypoints2, descriptors2 = orb.detectAndCompute(test_img_gray, None)
    
    if descriptors1 is None or descriptors2 is None:
        print("[WARNING] No keypoints found in at least one image.")
        return np.eye(3)  # Fallback: identity matrix
    
    matcher = cv2.DescriptorMatcher_create(cv2.DESCRIPTOR_MATCHER_BRUTEFORCE_HAMMING)
    matches = matcher.match(descriptors1, descriptors2)
    matches = sorted(matches, key=lambda x: x.distance)
    
    num_good = int(len(matches) * good_match_percent)
    matches = matches[:num_good]
    
    points1 = np.zeros((len(matches), 2), dtype=np.float32)
    points2 = np.zeros((len(matches), 2), dtype=np.float32)
    for i, match in enumerate(matches):
        points1[i, :] = keypoints1[match.queryIdx].pt
        points2[i, :] = keypoints2[match.trainIdx].pt
    
    homography, mask = cv2.findHomography(points2, points1, cv2.RANSAC)
    return homography

def measure_wear(ref_img_gray, test_img_gray_aligned, threshold_value=30):
    """
    Detects and measures the largest wear region by comparing ref_img_gray and an aligned test image.
    
    Returns a dict with:
        - 'area': area in pixels,
        - 'wear_depth': mean intensity difference within the wear region,
        - 'mask': binary image mask,
        - 'contour': approximated contour of the wear region.
    """
    ref_blur = cv2.GaussianBlur(ref_img_gray, (5, 5), 0)
    test_blur = cv2.GaussianBlur(test_img_gray_aligned, (5, 5), 0)
    
    diff = cv2.absdiff(ref_blur, test_blur)
    _, diff_thresh = cv2.threshold(diff, threshold_value, 255, cv2.THRESH_BINARY)
    
    kernel = np.ones((3, 3), np.uint8)
    diff_thresh = cv2.morphologyEx(diff_thresh, cv2.MORPH_OPEN, kernel, iterations=1)
    diff_thresh = cv2.morphologyEx(diff_thresh, cv2.MORPH_CLOSE, kernel, iterations=1)
    
    contours, _ = cv2.findContours(diff_thresh.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    if not contours:
        return {
            "area": 0,
            "wear_depth": 0,
            "mask": diff_thresh,
            "contour": None
        }
    
    largest_contour = max(contours, key=cv2.contourArea)
    area = cv2.contourArea(largest_contour)
    
    # Approximate contour to smooth the outline.
    epsilon = 0.01 * cv2.arcLength(largest_contour, True)
    approx = cv2.approxPolyDP(largest_contour, epsilon, True)
    
    # Create a mask and compute mean intensity difference (as a proxy for wear depth).
    contour_mask = np.zeros_like(diff_thresh)
    cv2.drawContours(contour_mask, [approx], -1, 255, cv2.FILLED)
    region_diff = cv2.bitwise_and(diff, diff, mask=contour_mask)
    nonzero_vals = region_diff[region_diff > 0]
    wear_depth = float(np.mean(nonzero_vals)) if len(nonzero_vals) > 0 else 0
    
    return {
        "area": area,
        "wear_depth": wear_depth,
        "mask": diff_thresh,
        "contour": approx
    }

def draw_dotted_contour(image_bgr, contour, color=(0, 100, 255), thickness=2, gap=6):
    """
    Draws a dotted contour along the given contour on the image.
    
    Args:
        image_bgr (np.ndarray): BGR image.
        contour (np.ndarray): Contour points (Nx1x2).
        color (tuple): BGR color.
        thickness (int): Dot thickness.
        gap (int): Gap between dots.
    """
    points = contour.reshape(-1, 2)
    num_points = len(points)
    for i in range(num_points):
        x1, y1 = points[i]
        x2, y2 = points[(i + 1) % num_points]
        dist = np.hypot(x2 - x1, y2 - y1)
        steps = max(1, int(dist // gap))
        for step in range(steps + 1):
            t = step / float(steps)
            x = int(x1 + (x2 - x1) * t)
            y = int(y1 + (y2 - y1) * t)
            cv2.circle(image_bgr, (x, y), thickness, color, -1)

def annotate_color_image(ref_img_gray, test_img_color, test_img_gray, homography, 
                         threshold_value=30, mm_per_pixel=0.05):
    """
    Warps the color and grayscale images of the worn sample using the homography.
    Measures wear using the warped grayscale image and then annotates the warped color image:
      - Draws a dotted contour around the wear region.
      - Annotates the image with wear area (in pixels and mm^2) and an estimated depth.
      
    Returns:
        measure_dict: results from measure_wear.
        annotated_color: annotated warped color image.
    """
    h, w = ref_img_gray.shape
    warped_color = cv2.warpPerspective(test_img_color, homography, (w, h))
    warped_gray = cv2.warpPerspective(test_img_gray, homography, (w, h))
    
    measure_dict = measure_wear(ref_img_gray, warped_gray, threshold_value)
    annotated_color = warped_color.copy()
    
    contour = measure_dict["contour"]
    if contour is not None:
        draw_dotted_contour(annotated_color, contour, color=(0, 100, 255), thickness=2, gap=6)
        
        # Prepare texts
        px_area = measure_dict["area"]
        area_mm2 = px_area * (mm_per_pixel ** 2)
        wear_depth = measure_dict["wear_depth"]
        text1 = f"Wear Area: {px_area:.1f} px ({area_mm2:.2f} mm^2)"
        text2 = f"Estimated Depth: {wear_depth:.2f}"
        
        # Define font parameters.
        font = cv2.FONT_HERSHEY_SIMPLEX
        scale = 0.6
        thick = 2
        # Determine size of text boxes.
        (tw1, th1), _ = cv2.getTextSize(text1, font, scale, thick)
        (tw2, th2), _ = cv2.getTextSize(text2, font, scale, thick)
        box_width  = max(tw1, tw2) + 10
        box_height = th1 + th2 + 10
        
        # Set top-left coordinate for the annotation box.
        x, y = 10, 30
        box_x1, box_y1 = x - 5, y - 5
        box_x2, box_y2 = x + box_width, y + box_height
        
        # --- Instead of blending the entire image, blend only the text ROI ---
        roi = annotated_color[box_y1:box_y2, box_x1:box_x2].copy()
        # Create an overlay of the same shape with the light pastel background color.
        rect_color = (200, 220, 200)  # light pastel (BGR)
        rect_overlay = np.full(roi.shape, rect_color, dtype=np.uint8)
        alpha = 0.5  # transparency factor
        blended_roi = cv2.addWeighted(roi, 1 - alpha, rect_overlay, alpha, 0)
        annotated_color[box_y1:box_y2, box_x1:box_x2] = blended_roi
        
        # Put text on the ROI.
        cv2.putText(annotated_color, text1, (x, y + th1), font, scale, (255, 255, 255), thick, cv2.LINE_AA)
        cv2.putText(annotated_color, text2, (x, y + th1 + th2 + 5), font, scale, (255, 255, 255), thick, cv2.LINE_AA)
    else:
        cv2.putText(annotated_color, "No wear detected", (10, 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
    
    return measure_dict, annotated_color

def process_image(ref_path, test_path, threshold_value=30, mm_per_pixel=0.05,
                  max_features=500, good_match_percent=0.15):
    """
    Reads the reference (grayscale) and worn images (color and grayscale),
    computes the homography for alignment, measures wear, and annotates the aligned
    color image with the wear contour and text.
    
    Returns:
        measure_dict: wear measurements.
        annotated_image: annotated color image.
    """
    # Read images.
    ref_img_gray = cv2.imread(ref_path, cv2.IMREAD_GRAYSCALE)
    test_img_color = cv2.imread(test_path, cv2.IMREAD_COLOR)
    test_img_gray = cv2.imread(test_path, cv2.IMREAD_GRAYSCALE)
    
    if ref_img_gray is None or test_img_color is None or test_img_gray is None:
        raise IOError(f"Could not read one or more images: {ref_path}, {test_path}")
    
    homography = align_images(ref_img_gray, test_img_gray, max_features, good_match_percent)
    measure_dict, annotated_image = annotate_color_image(ref_img_gray, test_img_color,
                                                          test_img_gray, homography,
                                                          threshold_value, mm_per_pixel)
    return measure_dict, annotated_image

def main():
    # Update these paths as needed.
    ref_path  = "tool_aa.jpg"  # Reference image (no wear)
    wear1_path = "tool_bb.jpg" # Worn sample B
    wear2_path = "tool_cc.jpg" # Worn sample C
    
    threshold_value = 10
    mm_per_pixel = 0.05  # Adjust according to calibration.
    
    print("[INFO] Processing worn image B...")
    measure_B, annotated_B = process_image(ref_path, wear1_path, threshold_value, mm_per_pixel)
    print("=== Results for Image B ===")
    print(f"  Wear Area (px)    : {measure_B['area']:.2f}")
    print(f"  Estimated Depth   : {measure_B['wear_depth']:.2f}")
    print(f"  Wear Area (mm^2)  : {measure_B['area'] * (mm_per_pixel**2):.2f}")
    cv2.imwrite("annotated_tool_b.jpg", annotated_B)
    
    print("[INFO] Processing worn image C...")
    measure_C, annotated_C = process_image(ref_path, wear2_path, threshold_value, mm_per_pixel)
    print("=== Results for Image C ===")
    print(f"  Wear Area (px)    : {measure_C['area']:.2f}")
    print(f"  Estimated Depth   : {measure_C['wear_depth']:.2f}")
    print(f"  Wear Area (mm^2)  : {measure_C['area'] * (mm_per_pixel**2):.2f}")
    cv2.imwrite("annotated_tool_c.jpg", annotated_C)
    
    # Optionally display results.
    cv2.imshow("Annotated Image B", annotated_B)
    cv2.imshow("Annotated Image C", annotated_C)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
