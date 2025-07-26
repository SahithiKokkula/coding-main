import cv2
import numpy as np
from skimage.measure import label, regionprops
import os

# -------------------------------
# Calibration: mm-per-pixel
# Accept both width and height for robustness
# -------------------------------
def get_mm_per_pixel(image_path, real_width_mm=None, real_height_mm=None):
    img = cv2.imread(image_path)
    if img is None:
        raise FileNotFoundError(f"Cannot load image: {image_path}")
    h, w = img.shape[:2]
    scales = []
    if real_width_mm:
        scales.append(real_width_mm / w)
    if real_height_mm:
        scales.append(real_height_mm / h)
    if not scales:
        raise ValueError("Provide real_width_mm and/or real_height_mm.")
    return float(np.mean(scales))

# -------------------------------
# Read & preprocess: color->gray, equalize, blur
# -------------------------------
def read_and_preprocess(path, blur_ksize=7):
    img = cv2.imread(path)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    gray = cv2.equalizeHist(gray)
    gray = cv2.GaussianBlur(gray, (blur_ksize, blur_ksize), 0)
    return img, gray

# -------------------------------
# Robust alignment: try SIFT, fallback to ORB
# -------------------------------
def align_images(ref_gray, target_gray, min_matches=8):
    # Attempt SIFT
    try:
        detector = cv2.SIFT_create()
    except AttributeError:
        detector = cv2.ORB_create(5000)
    kp1, des1 = detector.detectAndCompute(ref_gray, None)
    kp2, des2 = detector.detectAndCompute(target_gray, None)
    if des1 is None or des2 is None:
        return target_gray
    # Matcher
    matcher = cv2.BFMatcher(cv2.NORM_L2 if isinstance(detector, cv2.SIFT) else cv2.NORM_HAMMING)
    matches = matcher.knnMatch(des1, des2, k=2)
    # Ratio test
    good = [m for m,n in matches if m.distance < 0.75*n.distance]
    if len(good) < min_matches:
        return target_gray
    src = np.float32([kp1[m.queryIdx].pt for m in good]).reshape(-1,1,2)
    dst = np.float32([kp2[m.trainIdx].pt for m in good]).reshape(-1,1,2)
    H, _ = cv2.findHomography(dst, src, cv2.RANSAC, 5.0)
    aligned = cv2.warpPerspective(target_gray, H, (ref_gray.shape[1], ref_gray.shape[0]))
    return aligned

# -------------------------------
# Detect wear on side view: area, depths, volume
# -------------------------------
def detect_wear_side(ref_gray, wear_gray, color_img, mm_px,
                      diff_blur=5, area_thresh=300,
                      otsu_blur=5, morph_kernel=5):
    # Diff and blur
    diff = cv2.absdiff(ref_gray, wear_gray)
    diff = cv2.GaussianBlur(diff, (diff_blur, diff_blur), 0)
    # Otsu threshold for consistent segmentation
    _, bw = cv2.threshold(diff, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    # Morphology: close then open
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (morph_kernel, morph_kernel))
    clean = cv2.morphologyEx(bw, cv2.MORPH_CLOSE, kernel, iterations=2)
    clean = cv2.morphologyEx(clean, cv2.MORPH_OPEN,  kernel, iterations=1)

    # Label regions
    lbl = label(clean)
    mask = np.zeros_like(clean)
    total_area_px = 0
    volume_px3 = 0  # sum(depth_px * 1 pixel)
    max_depth_px = 0

    for region in regionprops(lbl):
        if region.area < area_thresh:
            continue
        coords = region.coords
        mask[coords[:,0], coords[:,1]] = 255
        total_area_px += region.area
        # estimate depth per pixel = diff value
        depths = diff[coords[:,0], coords[:,1]].astype(np.float32)
        volume_px3   += depths.sum()
        max_depth_px = max(max_depth_px, depths.max())

    # convert metrics
    area_mm2       = total_area_px * (mm_px**2)
    max_depth_mm   = max_depth_px   * mm_px
    volume_mm3     = volume_px3     * (mm_px**3)
    avg_depth_mm   = volume_mm3 / area_mm2 if area_mm2>0 else 0

    # Annotate
    contours,_ = cv2.findContours(mask.astype(np.uint8), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    overlay = color_img.copy()
    cv2.drawContours(overlay, contours, -1, (0,255,0), 2)
    annotated = cv2.addWeighted(color_img, 1.0, overlay, 0.4, 0)
    cv2.putText(annotated, f"A={area_mm2:.2f}mm2", (10,30), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)
    cv2.putText(annotated, f"Davg={avg_depth_mm:.3f}mm", (10,60), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)
    cv2.putText(annotated, f"Dmax={max_depth_mm:.3f}mm", (10,90), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)
    cv2.putText(annotated, f"V={volume_mm3:.2f}mm3", (10,120), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)

    return mask, area_mm2, avg_depth_mm, max_depth_mm, volume_mm3, annotated

# -------------------------------
# Detect wear on top view: area only
# -------------------------------
def detect_wear_top(ref_gray, wear_gray, color_img, mm_px,
                     blur_ksize=5, area_thresh=300, canny_thresh=(50,150),
                     close_kernel=7):
    # Use L channel for brightness diff
    # diff on gray
    diff = cv2.absdiff(ref_gray, wear_gray)
    diff = cv2.medianBlur(diff, blur_ksize)
    # Canny for edges of wear
    edges = cv2.Canny(diff, canny_thresh[0], canny_thresh[1])
    # Dilate edges to fill
    dil_k = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3,3))
    dil = cv2.dilate(edges, dil_k, iterations=2)
    # Close to solidify region
    clos = cv2.morphologyEx(dil, cv2.MORPH_CLOSE,
                            cv2.getStructuringElement(cv2.MORPH_ELLIPSE,(close_kernel,close_kernel)),
                            iterations=2)

    lbl = label(clos)
    mask = np.zeros_like(clos)
    total_area_px = 0
    for region in regionprops(lbl):
        if region.area < area_thresh:
            continue
        coords = region.coords
        mask[coords[:,0], coords[:,1]] = 255
        total_area_px += region.area

    area_mm2 = total_area_px * (mm_px**2)

    # Annotate
    contours,_ = cv2.findContours(mask.astype(np.uint8), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    overlay = color_img.copy()
    cv2.drawContours(overlay, contours, -1, (0,0,255), 2)
    annotated = cv2.addWeighted(color_img, 1.0, overlay, 0.4, 0)
    cv2.putText(annotated, f"A_top={area_mm2:.2f}mm2", (10,30), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)

    return mask, area_mm2, annotated

# -------------------------------
# Main: process side & top
# -------------------------------
def process_wear(ref_side, wear_side, ref_top, wear_top,
                 real_w_side_mm, real_w_top_mm, out_prefix="RESULT"):
    # calibrate
    mm_px_s = get_mm_per_pixel(ref_side, real_width_mm=real_w_side_mm)
    mm_px_t = get_mm_per_pixel(ref_top,  real_width_mm=real_w_top_mm)

    # side
    rc_s, rg_s = read_and_preprocess(ref_side)
    wc_s, wg_s = read_and_preprocess(wear_side)
    al_s = align_images(rg_s, wg_s)
    _, area_s, davg_s, dmax_s, vol_s, an_s = detect_wear_side(rg_s, al_s, wc_s, mm_px_s)
    cv2.imwrite(f"{out_prefix}_side.png", an_s)

    # top
    rc_t, rg_t = read_and_preprocess(ref_top)
    wc_t, wg_t = read_and_preprocess(wear_top)
    al_t = align_images(rg_t, wg_t)
    _, area_t, an_t = detect_wear_top(rg_t, al_t, wc_t, mm_px_t)
    cv2.imwrite(f"{out_prefix}_top.png", an_t)

    # results
    print(f"[SIDE] Area={area_s:.2f}mm², Davg={davg_s:.3f}mm, Dmax={dmax_s:.3f}mm, Vol={vol_s:.2f}mm³")
    print(f"[TOP ] Area={area_t:.2f}mm²")

    return {
        'side': {'area_mm2': area_s, 'avg_depth_mm': davg_s, 'max_depth_mm': dmax_s, 'volume_mm3': vol_s},
        'top': {'area_mm2': area_t}
    }

# Example usage:
res = process_wear("images/ref1.png","images/wear1.png","images/top_ref.jpg","images/top_wear.jpg",1.75,5.0)
print(res)
