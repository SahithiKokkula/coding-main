import cv2  # OpenCV for image processing
import numpy as np  # For numerical operations
from skimage.measure import label, regionprops  # For region-based measurements
import os  # For file path operations

# Input image paths
image_a = "ref1.png"  # Reference image (unworn tool)
image_b = "wear1.png"  # Worn image

# image dimentions : 4.65 mm X 2.78 mm
# actual wear dimentions (max depth .93 mm , avg depth 0.77 mm , wear length 2.60 mm, area 2.002 mm^2)
# generated depth (max depth 1.10 mm , area 1.68 mm)

# Function to compute the millimeter-per-pixel scale from a known dimension
def get_mm_per_pixel(image_path, real_width_mm=None, real_height_mm=None):
    img = cv2.imread(image_path)  # Load image
    if img is None:
        raise FileNotFoundError(f"Image not found or couldn't be loaded: {image_path}")
    h, w = img.shape[:2]  # Get image height and width

    # Compute scale using real-world width or height
    if real_width_mm:
        return real_width_mm / w
    elif real_height_mm:
        return real_height_mm / h
    else:
        raise ValueError("Please provide either real_width_mm or real_height_mm.")

# Get pixel-to-mm ratio from known tool width
mm_per_pixel = get_mm_per_pixel(image_a, real_width_mm=1.75)

# Function to read and preprocess image (grayscale + contrast enhancement)
def read_and_preprocess(path):
    img = cv2.imread(path)  # Read image
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)  # Convert to grayscale
    gray = cv2.equalizeHist(gray)  # Improve contrast
    return img, gray  # Return both color and grayscale versions

# Align the wear image with reference using SIFT keypoints
def align_images_sift(ref_gray, wear_gray):
    sift = cv2.SIFT_create()  # Create SIFT detector
    kp1, des1 = sift.detectAndCompute(ref_gray, None)  # Keypoints and descriptors for reference
    kp2, des2 = sift.detectAndCompute(wear_gray, None)  # Keypoints and descriptors for worn image

    bf = cv2.BFMatcher()  # Brute force matcher
    matches = bf.knnMatch(des1, des2, k=2)  # KNN matching

    good = []
    for m, n in matches:
        if m.distance < 0.75 * n.distance:  # Ratio test
            good.append(m)

    if len(good) < 4:
        print("⚠️ Not enough matches for homography. Skipping alignment.")
        return wear_gray  # Return as-is if not enough matches

    # Extract matched keypoints
    src_pts = np.float32([kp1[m.queryIdx].pt for m in good]).reshape(-1, 1, 2)
    dst_pts = np.float32([kp2[m.trainIdx].pt for m in good]).reshape(-1, 1, 2)
    

    # Estimate homography matrix
    matrix, mask = cv2.findHomography(dst_pts, src_pts, cv2.RANSAC)
    # Warp image to align with reference
    aligned = cv2.warpPerspective(wear_gray, matrix, (ref_gray.shape[1], ref_gray.shape[0]))
    return aligned

# Detect wear by comparing aligned images
def detect_wear(ref_img, wear_img, original_color):
    diff = cv2.absdiff(ref_img, wear_img)  # Absolute pixel-wise difference
    _, thresh = cv2.threshold(diff, 25, 255, cv2.THRESH_BINARY)  # Binary threshold

    kernel = np.ones((3, 3), np.uint8)  # Kernel for noise removal
    clean = cv2.morphologyEx(thresh, cv2.MORPH_OPEN, kernel)  # Clean small noise

    labeled = label(clean)  # Label connected components

    mask = np.zeros_like(clean)  # Final mask for wear region
    total_area = 0  # Initialize area
    max_depth = 0  # Initialize depth

    for region in regionprops(labeled):
        if region.area > 500:  # Ignore tiny regions
            coords = region.coords  # Get pixel coordinates
            mask[coords[:, 0], coords[:, 1]] = 255  # Mark as white in mask
            total_area += region.area  # Accumulate area
            max_depth = max(max_depth, region.bbox[2] - region.bbox[0])  # Vertical span = depth

    # Find contours from wear mask
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    overlay = original_color.copy()  # Make a copy for annotation

    # Draw yellow dots on contour (sampled)
    for cnt in contours:
        for i in range(0, len(cnt), 10):
            cv2.circle(overlay, tuple(cnt[i][0]), 1, (0, 255, 255), -1)

    # Combine overlay with original
    annotated = cv2.addWeighted(original_color, 1, overlay, 0.5, 0)

    # Convert pixel area and depth to mm
    area_mm = total_area * mm_per_pixel**2
    depth_mm = max_depth * mm_per_pixel

    # Put wear area and depth text on image
    cv2.putText(annotated, f"Wear Area: {area_mm:.2f} mm^2", (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)
    cv2.putText(annotated, f"Max Depth: {depth_mm:.2f} mm", (10, 60),
                cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)

    return area_mm, depth_mm, annotated  # Return results and image

# Show image in a popup window
def show_annotated_image(img):
    cv2.imshow("Annotated Image", img)  # Show image
    cv2.waitKey(0)  # Wait for key press
    cv2.destroyAllWindows()  # Close window

# Main tool processing logic
# work flow
def process_tool(ref_path, wear_path, out_name):
    ref_color, ref_gray = read_and_preprocess(ref_path)  # Read ref
    wear_color, wear_gray = read_and_preprocess(wear_path)  # Read wear
    aligned = align_images_sift(ref_gray, wear_gray)  # Align
    area, depth, annotated = detect_wear(ref_gray, aligned, wear_color)  # Detect wear
    print(f"[{out_name}] Area: {area:.2f} mm^2 | Depth: {depth:.2f} mm")  # Print results
    output_filename = f"{out_name}_annotated.png"  # File name
    cv2.imwrite(output_filename, annotated)  # Save annotated image
    show_annotated_image(annotated)  # Show result


# main calling 
process_tool(image_a, image_b, "TOOL_WEAR")
