import cv2
import numpy as np

def draw_dotted_rectangle(img, pt1, pt2, color, thickness=2, gap=5):
    """
    Draw a dotted rectangle with improved corner coverage.
    """
    x1, y1 = pt1
    x2, y2 = pt2

    # Draw horizontal lines
    for x in range(x1, x2, gap):
        if x + gap > x2:  # Ensure complete coverage at the end
            x = x2
        cv2.circle(img, (x, y1), thickness, color, -1)
        cv2.circle(img, (x, y2), thickness, color, -1)
    
    # Draw vertical lines
    for y in range(y1, y2, gap):
        if y + gap > y2:  # Ensure complete coverage at the end
            y = y2
        cv2.circle(img, (x1, y), thickness, color, -1)
        cv2.circle(img, (x2, y), thickness, color, -1)

def annotate_image(image, wear_results, mm_per_pixel=0.05):
    """
    Annotates image with dotted rectangle and measurements in mm/pixels.
    Uses only dotted lines and text without solid backgrounds.
    """
    annotated_image = cv2.cvtColor(image, cv2.COLOR_GRAY2BGR)
    bbox = wear_results.get("bounding_box")
    
    if bbox is not None:
        x, y, w, h = bbox
        
        # Draw dotted rectangle in cyan
        draw_dotted_rectangle(annotated_image, (x, y), (x+w, y+h), (255, 255, 0), thickness=2, gap=8)
        
        # Calculate real-world measurements
        w_mm = w * mm_per_pixel
        h_mm = h * mm_per_pixel
        area_mm2 = wear_results["area"] * (mm_per_pixel ** 2)
        
        # Create measurement texts
        texts = [
            f"W: {w_mm:.1f}mm ({w}px)  H: {h_mm:.1f}mm ({h}px)",
            f"Area: {area_mm2:.1f}mm² ({wear_results['area']}px)",
            f"Intensity Δ: {wear_results['mean_diff']:.1f}"
        ]
        
        # Text positioning parameters
        font = cv2.FONT_HERSHEY_SIMPLEX
        scale = 0.3
        thickness = 1
        text_color = (255, 255, 255)  # White text
        line_spacing = 25
        start_y = max(y - len(texts)*line_spacing, 20)  # Prevent text going off top
        
        # Draw texts with outline for better visibility
        for i, text in enumerate(texts):
            text_pos = (x, start_y + i*line_spacing)
            
            # Draw black outline
            cv2.putText(annotated_image, text, text_pos, font, scale, 
                       (0, 0, 0), thickness+1, cv2.LINE_AA)
            # Draw main text
            cv2.putText(annotated_image, text, text_pos, font, scale,
                       text_color, thickness, cv2.LINE_AA)
    else:
        # No wear detected message
        cv2.putText(annotated_image, "No wear detected", (10, 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
    
    return annotated_image

# ... Keep other functions (align_images, measure_wear, process_image, main) unchanged ...
def align_images(ref_img, test_img, max_features=500, good_match_percent=0.15):
    orb = cv2.ORB_create(max_features)
    keypoints1, descriptors1 = orb.detectAndCompute(ref_img, None)
    keypoints2, descriptors2 = orb.detectAndCompute(test_img, None)
    
    if descriptors1 is None or descriptors2 is None:
        print("[WARNING] No keypoints/descriptors detected in one or both images.")
        return test_img, np.eye(3)
    
    matcher = cv2.DescriptorMatcher_create(cv2.DESCRIPTOR_MATCHER_BRUTEFORCE_HAMMING)
    matches = matcher.match(descriptors1, descriptors2)
    matches = list(matches)
    matches.sort(key=lambda x: x.distance)
    
    num_good_matches = int(len(matches) * good_match_percent)
    matches = matches[:num_good_matches]
    
    points1 = np.zeros((len(matches), 2), dtype=np.float32)
    points2 = np.zeros((len(matches), 2), dtype=np.float32)
    
    for i, match in enumerate(matches):
        points1[i, :] = keypoints1[match.queryIdx].pt
        points2[i, :] = keypoints2[match.trainIdx].pt

    homography, mask = cv2.findHomography(points2, points1, cv2.RANSAC)
    height, width = ref_img.shape
    aligned_img = cv2.warpPerspective(test_img, homography, (width, height))
    
    return aligned_img, homography

def measure_wear(reference_image, test_image, threshold_value=30):
    ref_blur = cv2.GaussianBlur(reference_image, (5, 5), 0)
    test_blur = cv2.GaussianBlur(test_image, (5, 5), 0)
    
    diff = cv2.absdiff(ref_blur, test_blur)
    _, diff_thresh = cv2.threshold(diff, threshold_value, 255, cv2.THRESH_BINARY)
    
    kernel = np.ones((3, 3), np.uint8)
    diff_thresh = cv2.morphologyEx(diff_thresh, cv2.MORPH_OPEN, kernel, iterations=1)
    diff_thresh = cv2.morphologyEx(diff_thresh, cv2.MORPH_CLOSE, kernel, iterations=1)
    
    contours, _ = cv2.findContours(diff_thresh.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    if not contours:
        return {
            "area": 0,
            "mean_diff": 0,
            "mask": diff_thresh,
            "bounding_box": None
        }
    
    largest_contour = max(contours, key=cv2.contourArea)
    area = cv2.contourArea(largest_contour)
    bounding_box = cv2.boundingRect(largest_contour)  # (x, y, w, h)
    
    contour_mask = np.zeros_like(diff_thresh)
    cv2.drawContours(contour_mask, [largest_contour], -1, color=255, thickness=-1)
    
    masked_diff = cv2.bitwise_and(diff, diff, mask=contour_mask)
    nonzero_pixels = masked_diff[masked_diff > 0]
    mean_diff = np.mean(nonzero_pixels) if len(nonzero_pixels) > 0 else 0
    
    return {
        "area": area,
        "mean_diff": mean_diff,
        "mask": diff_thresh,
        "bounding_box": bounding_box
    }

def process_image(reference_path, test_path, threshold_value=30):
    ref_img = cv2.imread(reference_path, cv2.IMREAD_GRAYSCALE)
    test_img = cv2.imread(test_path, cv2.IMREAD_GRAYSCALE)
    
    if ref_img is None or test_img is None:
        raise IOError("Error loading one or more images. Check file paths.")
    
    print(f"[INFO] Loaded {reference_path} and {test_path}.")
    
    aligned_img, homography = align_images(ref_img, test_img)
    print(f"[INFO] Alignment complete. Homography:\n{homography}")
    
    wear_results = measure_wear(ref_img, aligned_img, threshold_value=threshold_value)
    
    return {
        "results": wear_results,
        "aligned_img": aligned_img,
        "homography": homography
    }
def main():
    # Update the image paths below.
    ref_path  = "t3.jpg"  # Reference image
    wear1_path = "t4.jpg" # Worn sample B
    
    threshold_value = 30
    mm_per_pixel = 0.05  # Adjust this value based on your calibration.
    print("[INFO] Processing worn image B...")
    result_B = process_image(ref_path, wear1_path, threshold_value)
    wear_B_results = result_B["results"]
    print("Wear measurement (Image B):")
    print(f"  Area: {wear_B_results['area']:.2f} pixels")
    print(f"  Mean Diff: {wear_B_results['mean_diff']:.2f}")
    wear_B_area = result_B["results"]["area"]
    wear_B_area_mm2 = wear_B_area * (mm_per_pixel ** 2)
    print(f"Wear area in mm^2 for Image B: {wear_B_area_mm2:.2f}")

    annotated_img_B = annotate_image(result_B["aligned_img"], wear_B_results, mm_per_pixel)
    cv2.imwrite("annotated_tool_b.jpg", annotated_img_B)
    
    # Optionally, display the images.
    cv2.imshow("Annotated Image B", annotated_img_B)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()