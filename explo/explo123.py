
import cv2
import numpy as np
from skimage.measure import label, regionprops
import os

image_a = "11.png"
image_b = "22.png"

def get_mm_per_pixel(image_path, real_width_mm=None, real_height_mm=None):
    img = cv2.imread(image_path)

    if img is None:
        raise FileNotFoundError(f"Image not found or couldn't be loaded: {image_path}")

    h, w = img.shape[:2]

    if real_width_mm:
        return real_width_mm / w
    elif real_height_mm:
        return real_height_mm / h
    else:
        raise ValueError("Please provide either real_width_mm or real_height_mm.")

mm_per_pixel = get_mm_per_pixel(image_a, real_width_mm=1.75)  # Adjust as per real microscope scale



# image dimentions : 4.65 mm X 2.78 mm
# actual wear dimentions (max depth .93 mm , avg depth 0.77 mm , wear length 2.60 mm, area 2.002 mm^2)
# generated depth (max depth 1.10 mm , area 1.68 mm)

def read_and_preprocess(path):
    img = cv2.imread(path)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # Enhance contrast
    gray = cv2.equalizeHist(gray)
    return img, gray

def align_images_sift(ref_gray, wear_gray):
    sift = cv2.SIFT_create()
    kp1, des1 = sift.detectAndCompute(ref_gray, None)
    kp2, des2 = sift.detectAndCompute(wear_gray, None)

    bf = cv2.BFMatcher()
    matches = bf.knnMatch(des1, des2, k=2)

    good = []
    for m, n in matches:
        if m.distance < 0.75 * n.distance:
            good.append(m)

    if len(good) < 4:
        print("⚠️ Not enough matches for homography. Skipping alignment.")
        return wear_gray  # Return original if can't align

    src_pts = np.float32([kp1[m.queryIdx].pt for m in good]).reshape(-1, 1, 2)
    dst_pts = np.float32([kp2[m.trainIdx].pt for m in good]).reshape(-1, 1, 2)

    matrix, mask = cv2.findHomography(dst_pts, src_pts, cv2.RANSAC)
    aligned = cv2.warpPerspective(wear_gray, matrix, (ref_gray.shape[1], ref_gray.shape[0]))
    return aligned

def detect_wear(ref_img, wear_img, original_color):
    diff = cv2.absdiff(ref_img, wear_img)
    _, thresh = cv2.threshold(diff, 25, 255, cv2.THRESH_BINARY)

    kernel = np.ones((3, 3), np.uint8)
    clean = cv2.morphologyEx(thresh, cv2.MORPH_OPEN, kernel)
    labeled = label(clean)

    mask = np.zeros_like(clean)
    total_area = 0
    max_depth = 0

    for region in regionprops(labeled):
        if region.area > 500:
            coords = region.coords
            mask[coords[:, 0], coords[:, 1]] = 255
            total_area += region.area
            max_depth = max(max_depth, region.bbox[2] - region.bbox[0])

    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    overlay = original_color.copy()

    for cnt in contours:
        for i in range(0, len(cnt), 10):
            cv2.circle(overlay, tuple(cnt[i][0]), 1, (0, 255, 255), -1)

    annotated = cv2.addWeighted(original_color, 1, overlay, 0.5, 0)

    # Add text
    area_mm = total_area * mm_per_pixel**2
    depth_mm = max_depth * mm_per_pixel
    cv2.putText(annotated, f"Wear Area: {area_mm:.2f} mm^2", (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)
    cv2.putText(annotated, f"Max Depth: {depth_mm:.2f} mm", (10, 60),
                cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)

    return area_mm, depth_mm, annotated

def process_tool(ref_path, wear_path, out_name):
    ref_color, ref_gray = read_and_preprocess(ref_path)
    wear_color, wear_gray = read_and_preprocess(wear_path)
    aligned = align_images_sift(ref_gray, wear_gray)
    area, depth, annotated = detect_wear(ref_gray, aligned, wear_color)
    print(f"[{out_name}] Area: {area:.2f} mm^2 | Depth: {depth:.2f} mm")
    cv2.imwrite(f"{out_name}_annotated.png", annotated)

# Example usage
process_tool(image_a, image_b, "ToolA")
# process_tool("ToolB_ref.png", "ToolB_wear.png", "ToolB")
# process_tool("ToolC_ref.png", "ToolC_wear.png", "ToolC")


