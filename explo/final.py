import cv2  # OpenCV for image processing
import numpy as np  # For numerical operations
from skimage.measure import label, regionprops  # For region-based measurements
import os  # For file path operations

# ----------------------
# Utility: compute millimetres-per-pixel scale
# ----------------------
def get_mm_per_pixel(image_path, real_width_mm=None, real_height_mm=None):
    img = cv2.imread(image_path)
    if img is None:
        raise FileNotFoundError(f"Image not found: {image_path}")
    h, w = img.shape[:2]

    if real_width_mm:
        return real_width_mm / w
    elif real_height_mm:
        return real_height_mm / h
    else:
        raise ValueError("Provide real_width_mm or real_height_mm.")

# ----------------------
# Read and preprocess image (grayscale + equalize)
# ----------------------
def read_and_preprocess(path):
    img = cv2.imread(path)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    gray = cv2.equalizeHist(gray)
    return img, gray

# ----------------------
# Align two grayscale images via SIFT-based homography
# ----------------------
def align_images_sift(ref_gray, wear_gray):
    sift = cv2.SIFT_create()
    kp1, des1 = sift.detectAndCompute(ref_gray, None)
    kp2, des2 = sift.detectAndCompute(wear_gray, None)

    bf = cv2.BFMatcher()
    matches = bf.knnMatch(des1, des2, k=2)
    good = [m for m,n in matches if m.distance < 0.75 * n.distance]

    if len(good) < 4:
        print("⚠️ Not enough matches for alignment, skipping.")
        return wear_gray

    src_pts = np.float32([kp1[m.queryIdx].pt for m in good]).reshape(-1,1,2)
    dst_pts = np.float32([kp2[m.trainIdx].pt for m in good]).reshape(-1,1,2)
    H, _ = cv2.findHomography(dst_pts, src_pts, cv2.RANSAC)
    aligned = cv2.warpPerspective(wear_gray, H, (ref_gray.shape[1], ref_gray.shape[0]))
    return aligned

# ----------------------
# Detect wear from a pair of aligned grayscale images
# Returns: mask (binary), area_mm2, avg_depth_mm, max_depth_mm, annotated color image
# ----------------------
def detect_wear(ref_gray, wear_gray, original_color, mm_per_pixel, area_thresh_px=500, diff_thresh=25):
    diff = cv2.absdiff(ref_gray, wear_gray)
    _, bw = cv2.threshold(diff, diff_thresh, 255, cv2.THRESH_BINARY)
    clean = cv2.morphologyEx(bw, cv2.MORPH_OPEN, np.ones((3,3),np.uint8))
    lbl = label(clean)

    mask = np.zeros_like(clean)
    total_area_px = 0
    weighted_depth = 0
    max_depth_px = 0

    for region in regionprops(lbl):
        if region.area < area_thresh_px:
            continue
        coords = region.coords
        mask[coords[:,0], coords[:,1]] = 255
        total_area_px += region.area
        # vertical span in px = depth
        depth_px = region.bbox[2] - region.bbox[0]
        weighted_depth += depth_px * region.area
        max_depth_px = max(max_depth_px, depth_px)

    # compute mm metrics
    area_mm2 = total_area_px * mm_per_pixel**2
    avg_depth_mm = (weighted_depth / total_area_px) * mm_per_pixel if total_area_px>0 else 0
    max_depth_mm = max_depth_px * mm_per_pixel

    # annotate contour and metrics
    contours, _ = cv2.findContours(mask.astype(np.uint8), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    overlay = original_color.copy()
    for cnt in contours:
        for i in range(0, len(cnt), 10):
            cv2.circle(overlay, tuple(cnt[i][0]), 1, (0,255,255), -1)
    annotated = cv2.addWeighted(original_color, 1.0, overlay, 0.5, 0)
    cv2.putText(annotated, f"Area: {area_mm2:.2f} mm^2", (10,30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255,255,255),2)
    cv2.putText(annotated, f"Avg Depth: {avg_depth_mm:.2f} mm", (10,60), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)
    cv2.putText(annotated, f"Max Depth: {max_depth_mm:.2f} mm", (10,90), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)

    return mask, area_mm2, avg_depth_mm, max_depth_mm, annotated

# ----------------------
# Main processing: side view and top view
# ----------------------
def process_wear(ref_side, wear_side, ref_top, wear_top,
                 real_width_side_mm, real_width_top_mm,
                 out_prefix="RESULT"):
    # compute scales
    mm_per_px_side = get_mm_per_pixel(ref_side, real_width_mm=real_width_side_mm)
    mm_per_px_top  = get_mm_per_pixel(ref_top,  real_width_mm=real_width_top_mm)

    # side view detection
    ref_color_s, ref_gray_s = read_and_preprocess(ref_side)
    wear_color_s, wear_gray_s = read_and_preprocess(wear_side)
    aligned_side = align_images_sift(ref_gray_s, wear_gray_s)
    mask_s, area_side, avg_depth, max_depth, anno_s = detect_wear(
        ref_gray_s, aligned_side, wear_color_s, mm_per_px_side)

    cv2.imwrite(f"{out_prefix}_side_annotated.png", anno_s)
    print(f"[SIDE VIEW] Area = {area_side:.2f} mm^2, Avg Depth = {avg_depth:.2f} mm, Max Depth = {max_depth:.2f} mm")

    # top view detection (only area)
    ref_color_t, ref_gray_t = read_and_preprocess(ref_top)
    wear_color_t, wear_gray_t = read_and_preprocess(wear_top)
    aligned_top = align_images_sift(ref_gray_t, wear_gray_t)
    mask_t, area_top, _, _, anno_t = detect_wear(
        ref_gray_t, aligned_top, wear_color_t, mm_per_px_top)

    cv2.imwrite(f"{out_prefix}_top_annotated.png", anno_t)
    print(f"[TOP VIEW ] Area = {area_top:.2f} mm^2")

    # volume = top area * avg depth (approximation)
    volume_mm3 = area_top * avg_depth
    print(f"[WEAR VOLUME] ≈ {volume_mm3:.2f} mm^3")

    return {
        'side': {'area_mm2': area_side, 'avg_depth_mm': avg_depth, 'max_depth_mm': max_depth},
        'top':  {'area_mm2': area_top},
        'volume_mm3': volume_mm3
    }

# Example usage (uncomment and set paths/dimensions):
results = process_wear(
    ref_side="ref1.png", wear_side="wear1.png",
    ref_top="top_ref.jpg", wear_top="top_wear.jpg",
    real_width_side_mm=1.75, real_width_top_mm=5.00,
    out_prefix="TOOL_WEAR"
)
print(results)
