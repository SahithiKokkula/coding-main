import cv2  # OpenCV for image processing
import numpy as np  # For numerical operations
from skimage.measure import label, regionprops  # For region-based measurements
import os

# --------------------------------------
# Utility: compute mm-per-pixel scale
# Accepts both width and height mm to average
# --------------------------------------
def get_mm_per_pixel(image_path, real_width_mm=None, real_height_mm=None):
    img = cv2.imread(image_path)
    if img is None:
        raise FileNotFoundError(f"Image not found: {image_path}")
    h, w = img.shape[:2]
    ratios = []
    if real_width_mm:
        ratios.append(real_width_mm / w)
    if real_height_mm:
        ratios.append(real_height_mm / h)
    if not ratios:
        raise ValueError("Provide at least one of real_width_mm or real_height_mm.")
    return sum(ratios) / len(ratios)

# --------------------------------------
# Preprocess: grayscale, equalize, blur
# --------------------------------------
def read_and_preprocess(path, blur_ksize=5):
    img = cv2.imread(path)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    gray = cv2.equalizeHist(gray)
    gray = cv2.GaussianBlur(gray, (blur_ksize, blur_ksize), 0)
    return img, gray

# --------------------------------------
# Align via SIFT homography
# --------------------------------------
def align_images_sift(ref_gray, wear_gray, min_matches=8):
    sift = cv2.SIFT_create()
    kp1, des1 = sift.detectAndCompute(ref_gray, None)
    kp2, des2 = sift.detectAndCompute(wear_gray, None)
    bf = cv2.BFMatcher()
    matches = bf.knnMatch(des1, des2, k=2)
    good = [m for m,n in matches if m.distance < 0.75*n.distance]
    if len(good) < min_matches:
        print("⚠️ Not enough matches; skipping alignment.")
        return wear_gray
    src_pts = np.float32([kp1[m.queryIdx].pt for m in good]).reshape(-1,1,2)
    dst_pts = np.float32([kp2[m.trainIdx].pt for m in good]).reshape(-1,1,2)
    H, _ = cv2.findHomography(dst_pts, src_pts, cv2.RANSAC)
    aligned = cv2.warpPerspective(wear_gray, H, (ref_gray.shape[1], ref_gray.shape[0]))
    return aligned

# --------------------------------------
# Detect wear: improved thresholding & morphology
# --------------------------------------
def detect_wear(ref_gray, wear_gray, original_color, mm_per_pixel,
                diff_blur=3, area_thresh_px=200, block_size=51, C=5):
    # compute absolute difference
    diff = cv2.absdiff(ref_gray, wear_gray)
    diff = cv2.GaussianBlur(diff, (diff_blur, diff_blur), 0)

    # adaptive threshold to capture faint wear
    bw = cv2.adaptiveThreshold(diff, 255, cv2.ADAPTIVE_THRESH_MEAN_C,
                               cv2.THRESH_BINARY, block_size, C)
    # clean noise and fill holes
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5,5))
    clean = cv2.morphologyEx(bw, cv2.MORPH_CLOSE, kernel, iterations=2)
    clean = cv2.morphologyEx(clean, cv2.MORPH_OPEN, kernel, iterations=1)

    # label connected components
    lbl = label(clean)
    mask = np.zeros_like(clean)
    total_area_px = 0
    weighted_depth_px = 0
    max_depth_px = 0

    for region in regionprops(lbl):
        if region.area < area_thresh_px:
            continue
        coords = region.coords
        mask[coords[:,0], coords[:,1]] = 255
        total_area_px += region.area
        # depth as pixel difference intensity
        local_depth_px = np.percentile(diff[coords[:,0], coords[:,1]], 90)
        weighted_depth_px += local_depth_px * region.area
        max_depth_px = max(max_depth_px, local_depth_px)

    # convert to mm
    area_mm2 = total_area_px * (mm_per_pixel**2)
    avg_depth_mm = (weighted_depth_px / total_area_px) * mm_per_pixel if total_area_px else 0
    max_depth_mm = max_depth_px * mm_per_pixel

    # annotate
    contours, _ = cv2.findContours(mask.astype(np.uint8), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    overlay = original_color.copy()
    for cnt in contours:
        cv2.drawContours(overlay, [cnt], -1, (0,255,0), 2)
    annotated = cv2.addWeighted(original_color, 1.0, overlay, 0.4, 0)
    cv2.putText(annotated, f"Area: {area_mm2:.2f} mm^2", (10,30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255,255,255),2)
    cv2.putText(annotated, f"Avg Depth: {avg_depth_mm:.3f} mm", (10,60), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255,255,255),2)
    cv2.putText(annotated, f"Max Depth: {max_depth_mm:.3f} mm", (10,90), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255,255,255),2)

    return mask, area_mm2, avg_depth_mm, max_depth_mm, annotated

# --------------------------------------
# Process both side & top views with improved logic
# --------------------------------------
def process_wear(ref_side, wear_side, ref_top, wear_top,
                 real_w_side_mm, real_w_top_mm, out_prefix="RESULT"):
    # calibration
    mm_px_side = get_mm_per_pixel(ref_side, real_width_mm=real_w_side_mm)
    mm_px_top  = get_mm_per_pixel(ref_top,  real_width_mm=real_w_top_mm)

    # side
    ref_c_s, ref_g_s = read_and_preprocess(ref_side)
    w_c_s, w_g_s = read_and_preprocess(wear_side)
    aligned_s = align_images_sift(ref_g_s, w_g_s)
    _, area_s, avg_d_s, max_d_s, ann_s = detect_wear(
        ref_g_s, aligned_s, w_c_s, mm_px_side)
    cv2.imwrite(f"{out_prefix}_side.png", ann_s)

    # top (area only)
    ref_c_t, ref_g_t = read_and_preprocess(ref_top)
    w_c_t, w_g_t = read_and_preprocess(wear_top)
    aligned_t = align_images_sift(ref_g_t, w_g_t)
    _, area_t, _, _, ann_t = detect_wear(
        ref_g_t, aligned_t, w_c_t, mm_px_top)
    cv2.imwrite(f"{out_prefix}_top.png", ann_t)

    # approximate volume
    volume_mm3 = area_t * avg_d_s

    print(f"[SIDE] Area={area_s:.2f}mm², AvgD={avg_d_s:.3f}mm, MaxD={max_d_s:.3f}mm")
    print(f"[TOP ] Area={area_t:.2f}mm²")
    print(f"[VOL ] ≈{volume_mm3:.2f}mm³")

    return {
        'side': {'area_mm2': area_s, 'avg_depth_mm': avg_d_s, 'max_depth_mm': max_d_s},
        'top':  {'area_mm2': area_t},
        'volume_mm3': volume_mm3
    }

# Example:
res = process_wear("ref1.png","wear1.png","top_ref.jpg","top_wear.jpg",1.75,5.0)
print(res)
