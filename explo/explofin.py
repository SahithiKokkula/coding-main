import cv2
import numpy as np
import matplotlib.pyplot as plt
from skimage.measure import label, regionprops
import os

# --- SETTINGS ---
mm_per_pixel = 0.005  # adjust this according to your microscope calibration
area_threshold_px = 500  # ignore tiny specks

# --- FUNCTIONS ---
def read_and_preprocess(path):
    img = cv2.imread(path)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    return img, gray

def align_images(ref_gray, wear_gray):
    orb = cv2.ORB_create(5000)
    kp1, des1 = orb.detectAndCompute(ref_gray, None)
    kp2, des2 = orb.detectAndCompute(wear_gray, None)

    bf = cv2.BFMatcher(cv2.NORM_HAMMING)
    matches = bf.knnMatch(des1, des2, k=2)

    # Lowe’s ratio test
    good = []
    for m, n in matches:
        if m.distance < 0.75 * n.distance:
            good.append(m)

    if len(good) < 4:
        raise ValueError("Not enough keypoints for homography!")

    pts1 = np.float32([kp1[m.queryIdx].pt for m in good])
    pts2 = np.float32([kp2[m.trainIdx].pt for m in good])

    matrix, _ = cv2.findHomography(pts2, pts1, cv2.RANSAC)
    aligned = cv2.warpPerspective(wear_gray, matrix, (ref_gray.shape[1], ref_gray.shape[0]))
    return aligned

def detect_wear(ref_img, aligned_img, original_img):
    diff = cv2.absdiff(ref_img, aligned_img)
    _, thresh = cv2.threshold(diff, 30, 255, cv2.THRESH_BINARY)

    kernel = np.ones((3,3),np.uint8)
    clean = cv2.morphologyEx(thresh, cv2.MORPH_OPEN, kernel)

    labeled = label(clean)
    total_area = 0
    max_depth = 0
    mask = np.zeros_like(clean)

    for region in regionprops(labeled):
        if region.area > area_threshold_px:
            minr, minc, maxr, maxc = region.bbox
            rr, cc = region.coords[:,0], region.coords[:,1]
            mask[rr, cc] = 255
            total_area += region.area
            max_depth = max(max_depth, maxr - minr)

    # Convert to mm
    area_mm = total_area * (mm_per_pixel**2)
    depth_mm = max_depth * mm_per_pixel

    # --- Annotate ---
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    overlay = original_img.copy()
    cv2.drawContours(overlay, contours, -1, (0, 255, 255), 2, lineType=cv2.LINE_4)

    # Transparent overlay
    annotated = cv2.addWeighted(original_img, 1, overlay, 0.5, 0)

    # Dotted line
    for cnt in contours:
        for i in range(0, len(cnt), 10):
            cv2.circle(annotated, tuple(cnt[i][0]), 1, (0, 255, 0), -1)

    # --- Text ---
    cv2.putText(annotated, f"Wear Area: {area_mm:.2f} mm^2", (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)
    cv2.putText(annotated, f"Max Depth: {depth_mm:.2f} mm", (10, 60),
                cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)

    return area_mm, depth_mm, annotated

# --- MAIN WORKFLOW ---
def process_tool(reference_path, test_path, output_name):
    ref_color, ref_gray = read_and_preprocess(reference_path)
    test_color, test_gray = read_and_preprocess(test_path)

    aligned_gray = align_images(ref_gray, test_gray)
    area, depth, annotated_img = detect_wear(ref_gray, aligned_gray, test_color)

    print(f"[{output_name}] Area = {area:.2f} mm^2 | Depth = {depth:.2f} mm")
    cv2.imwrite(f"{output_name}_annotated.png", annotated_img)

# --- EXAMPLES (Update these paths) ---
process_tool("11.png", "22.png", "ToolA")
# process_tool("tool_a.png", "tool_b.png", "ToolB")
# process_tool("tool_a.png", "tool_c.png", "ToolC")

