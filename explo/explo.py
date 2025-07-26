import cv2
import numpy as np

def align_images(ref_img, test_img, max_features=500, good_match_percent=0.15):
    """
    Aligns test_img to ref_img using ORB feature matching and homography.
    """
    # 1. Detect ORB features and compute descriptors
    orb = cv2.ORB_create(max_features)
    keypoints1, descriptors1 = orb.detectAndCompute(ref_img, None)
    keypoints2, descriptors2 = orb.detectAndCompute(test_img, None)
    
    # Defensive check: if no descriptors were found, return the original test image
    if descriptors1 is None or descriptors2 is None:
        print("[WARNING] No keypoints/descriptors detected in at least one of the images.")
        # Return test_img as-is and the identity matrix as the 'homography'
        return test_img, np.eye(3)

    # 2. Match features
    matcher = cv2.DescriptorMatcher_create(cv2.DESCRIPTOR_MATCHER_BRUTEFORCE_HAMMING)

    # Depending on your OpenCV version, you might not need the third arg
    matches = matcher.match(descriptors1, descriptors2)

    # Convert to list if necessary
    matches = list(matches)

    # 3. Sort matches by distance
    matches.sort(key=lambda x: x.distance)

    # 4. Remove not-so-good matches
    num_good_matches = int(len(matches) * good_match_percent)
    matches = matches[:num_good_matches]

    # 5. Extract location of good matches
    points1 = np.zeros((len(matches), 2), dtype=np.float32)
    points2 = np.zeros((len(matches), 2), dtype=np.float32)

    for i, match in enumerate(matches):
        points1[i, :] = keypoints1[match.queryIdx].pt
        points2[i, :] = keypoints2[match.trainIdx].pt

    # 6. Find homography
    homography, mask = cv2.findHomography(points2, points1, cv2.RANSAC)
    
    # 7. Warp the test image using the homography
    height, width = ref_img.shape
    aligned_img = cv2.warpPerspective(test_img, homography, (width, height))
    
    return aligned_img, homography


def measure_wear(reference_image, test_image, threshold_value=30):
    """
    Compares the reference image to the aligned test (worn) image and measures wear.
    
    Args:
        reference_image (np.ndarray): Grayscale reference (no wear) image.
        test_image (np.ndarray): Grayscale worn image (should be aligned to the reference).
        threshold_value (int): Threshold for binarization.
        
    Returns:
        dict: Contains measured wear area (in pixels), mean intensity difference,
              and binary wear mask.
    """
    # Apply a slight blur to reduce noise before computing difference.
    ref_blur = cv2.GaussianBlur(reference_image, (5, 5), 0)
    test_blur = cv2.GaussianBlur(test_image, (5, 5), 0)
    
    # Compute the absolute difference.
    diff = cv2.absdiff(ref_blur, test_blur)
    
    # Threshold the difference image.
    _, diff_thresh = cv2.threshold(diff, threshold_value, 255, cv2.THRESH_BINARY)
    
    # Refine the mask using morphological operations.
    kernel = np.ones((3, 3), np.uint8)
    diff_thresh = cv2.morphologyEx(diff_thresh, cv2.MORPH_OPEN, kernel, iterations=1)
    diff_thresh = cv2.morphologyEx(diff_thresh, cv2.MORPH_CLOSE, kernel, iterations=1)
    
    # Find contours in the thresholded image.
    contours, _ = cv2.findContours(diff_thresh.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    if not contours:
        # No wear regions detected.
        return {
            "area": 0,
            "mean_diff": 0,
            "mask": diff_thresh
        }
    
    # Use the largest contour as the main wear area.
    largest_contour = max(contours, key=cv2.contourArea)
    
    # Calculate the area (in pixels).
    area = cv2.contourArea(largest_contour)
    
    # Create a mask for the detected wear region.
    contour_mask = np.zeros_like(diff_thresh)
    cv2.drawContours(contour_mask, [largest_contour], -1, color=255, thickness=-1)
    
    # Compute mean intensity difference within that region.
    masked_diff = cv2.bitwise_and(diff, diff, mask=contour_mask)
    nonzero_pixels = masked_diff[masked_diff > 0]
    mean_diff = np.mean(nonzero_pixels) if len(nonzero_pixels) > 0 else 0
    
    return {
        "area": area,
        "mean_diff": mean_diff,
        "mask": diff_thresh
    }

def process_image(reference_path, test_path, threshold_value=30):
    """
    Loads the reference and test images, aligns the test image, measures wear,
    and returns the results along with the aligned image.
    
    Args:
        reference_path (str): File path to the reference image.
        test_path (str): File path to the test (worn) image.
        threshold_value (int): Threshold value for the wear measurement.
        
    Returns:
        dict: A dictionary containing:
              - 'results': wear measurement dictionary from measure_wear.
              - 'aligned_img': the aligned test image.
              - 'homography': the homography matrix used for alignment.
    """
    # Read images as grayscale.
    ref_img = cv2.imread(reference_path, cv2.IMREAD_GRAYSCALE)
    test_img = cv2.imread(test_path, cv2.IMREAD_GRAYSCALE)
    
    if ref_img is None or test_img is None:
        raise IOError("Error loading one or more images. Check your file paths.")
    
    print(f"[INFO] Loaded reference image ({reference_path}) and test image ({test_path}).")
    
    # Align the test image to the reference image.
    aligned_img, homography = align_images(ref_img, test_img)
    print(f"[INFO] Image alignment complete. Homography matrix:\n{homography}")
    
    # Optional: Save or display the aligned image for inspection.
    # cv2.imwrite("aligned_test.jpg", aligned_img)
    
    # Calculate the wear measurement.
    wear_results = measure_wear(ref_img, aligned_img, threshold_value=threshold_value)
    
    return {
        "results": wear_results,
        "aligned_img": aligned_img,
        "homography": homography
    }

def main():
    # =========================================================================
    # Paths to your images. Replace these with your actual file locations.
    # Reference image A (no wear) and worn images B and C.
    # =========================================================================
    ref_path  = "tool_a.jpg"  # Reference image (no wear)
    wear1_path = "tool_b.jpg" # Worn image sample 1
    wear2_path = "tool_c.jpg" # Worn image sample 2
    
    # Set your threshold value (adjust based on your image conditions).
    threshold_value = 30
    
    # ----------------------------
    # Process worn image B.
    # ----------------------------
    print("[INFO] Processing worn image B...")
    result_B = process_image(ref_path, wear1_path, threshold_value)
    wear_B_area = result_B["results"]["area"]
    wear_B_mean_diff = result_B["results"]["mean_diff"]
    print("Wear measurement (Image B):")
    print(f"  Wear area (pixels)       : {wear_B_area:.2f}")
    print(f"  Mean intensity difference: {wear_B_mean_diff:.2f}")
    
    # ----------------------------
    # Process worn image C.
    # ----------------------------
    print("\n[INFO] Processing worn image C...")
    result_C = process_image(ref_path, wear2_path, threshold_value)
    wear_C_area = result_C["results"]["area"]
    wear_C_mean_diff = result_C["results"]["mean_diff"]
    print("Wear measurement (Image C):")
    print(f"  Wear area (pixels)       : {wear_C_area:.2f}")
    print(f"  Mean intensity difference: {wear_C_mean_diff:.2f}")
    
    # ================================
    # Optional: Visualize the results.
    # ================================
    # To see the alignment and mask for debugging, uncomment:
    # cv2.imshow("Aligned Image B", result_B["aligned_img"])
    # cv2.imshow("Wear Mask B", result_B["results"]["mask"])
    # cv2.imshow("Aligned Image C", result_C["aligned_img"])
    # cv2.imshow("Wear Mask C", result_C["results"]["mask"])
    # cv2.waitKey(0)
    # cv2.destroyAllWindows()
    
    # ================================
    # Optional: Calibration
    # ================================
    # If you have a known scale (e.g., pixels per millimeter), you can convert
    # the area from pixels to real-world units here.
    # Example:
    # scale = 0.1  # mm per pixel (replace with your actual value)
    # wear_B_area_mm2 = wear_B_area * (scale ** 2)
    # print(f"Wear area in mm^2 for Image B: {wear_B_area_mm2:.2f}")

if __name__ == "__main__":
    main()
