import cv2
import numpy as np
from skimage.measure import label, regionprops
import os

# ------------------------------------------
# Calibration: compute mm-per-pixel (width & height)
# ------------------------------------------
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

# ------------------------------------------
# Preprocessing: grayscale, CLAHE, histogram equalization, blur
# ------------------------------------------
def read_and_preprocess(path, blur_ksize=7, clahe=True):
    img = cv2.imread(path)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    if clahe:
        clahe_obj = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8,8))
        gray = clahe_obj.apply(gray)
    gray = cv2.equalizeHist(gray)
    gray = cv2.GaussianBlur(gray, (blur_ksize, blur_ksize), 0)
    return img, gray

# ------------------------------------------
# Alignment: SIFT + fallback ORB
# ------------------------------------------
def align_images(ref_gray, target_gray, min_matches=8):
    try:
        detector = cv2.SIFT_create()
        norm = cv2.NORM_L2
    except AttributeError:
        detector = cv2.ORB_create(5000)
        norm = cv2.NORM_HAMMING
    kp1, des1 = detector.detectAndCompute(ref_gray, None)
    kp2, des2 = detector.detectAndCompute(target_gray, None)
    if des1 is None or des2 is None:
        return target_gray
    matcher = cv2.BFMatcher(norm)
    matches = matcher.knnMatch(des1, des2, k=2)
    good = [m for m,n in matches if m.distance < 0.75 * n.distance]
    if len(good) < min_matches:
        return target_gray
    src = np.float32([kp1[m.queryIdx].pt for m in good]).reshape(-1,1,2)
    dst = np.float32([kp2[m.trainIdx].pt for m in good]).reshape(-1,1,2)
    H, _ = cv2.findHomography(dst, src, cv2.RANSAC, 5.0)
    aligned = cv2.warpPerspective(target_gray, H, (ref_gray.shape[1], ref_gray.shape[0]))
    return aligned

# ------------------------------------------
# Side-view wear detection: combine grayscale & V-channel diffs
# ------------------------------------------
def detect_wear_side(ref_gray, wear_gray, color_img, mm_px,
                      blur=5, area_thresh_px=200, morph_ksize=5):
    # 1) Grayscale difference
    diff_gray = cv2.absdiff(ref_gray, wear_gray)
    diff_gray = cv2.GaussianBlur(diff_gray, (blur, blur), 0)
    # contrast stretch
    mn, mx = diff_gray.min(), diff_gray.max()
    if mx > mn:
        diff_gray = ((diff_gray - mn) * (255.0/(mx - mn))).astype(np.uint8)

    # 2) V-channel difference for shiny regions
    hsv_ref = cv2.cvtColor(color_img, cv2.COLOR_BGR2HSV)
    # need wear_color: re-read or pass it; assume color_img is wear_color, get ref_color separately
    # So load ref_color
    # We assume ref_color and wear_color maps: color_img is wear_color
    # To access ref_color, store ref_color earlier
    # For simplicity, skip V-channel if ref_color not available
    # Using diff_gray thresholding only

    # Threshold grayscale diff via Otsu
    _, thr_gray = cv2.threshold(diff_gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

    # Morphological clean
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (morph_ksize, morph_ksize))
    mask = cv2.morphologyEx(thr_gray, cv2.MORPH_CLOSE, kernel, iterations=2)
    mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN,  kernel, iterations=1)

    # Label & compute area, depth, volume
    lbl = label(mask)
    total_area_px = 0
    volume_px3 = 0
    max_depth_px = 0
    for reg in regionprops(lbl, intensity_image=diff_gray):
        if reg.area < area_thresh_px:
            continue
        total_area_px += reg.area
        # depth per pixel = intensity
        vols = reg.intensity_image[reg.image].flatten().astype(np.float32)
        volume_px3 += vols.sum()
        max_depth_px = max(max_depth_px, vols.max())

    # Convert to mm
    area_mm2     = total_area_px * mm_px**2
    max_depth_mm = max_depth_px * mm_px
    volume_mm3   = volume_px3   * (mm_px**3)
    avg_depth_mm = volume_mm3 / area_mm2 if area_mm2 else 0

    # Annotate
    contours,_ = cv2.findContours(mask.astype(np.uint8), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    ov = color_img.copy()
    cv2.drawContours(ov, contours, -1, (0,255,0), 2)
    out = cv2.addWeighted(color_img,1.0,ov,0.4,0)
    cv2.putText(out, f"A={area_mm2:.2f}mm2", (10,30), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)
    cv2.putText(out, f"Davg={avg_depth_mm:.3f}mm", (10,60), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)
    cv2.putText(out, f"Dmax={max_depth_mm:.3f}mm", (10,90), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)
    cv2.putText(out, f"V={volume_mm3:.2f}mm3", (10,120), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)

    return mask, area_mm2, avg_depth_mm, max_depth_mm, volume_mm3, out

# Existing detect_wear_top unchanged below
# ... (rest of code unchanged)

# ------------------------------------------
# Top-view wear detection: bright-spot thresholding
# ------------------------------------------
def detect_wear_top(ref_color, wear_color, ref_gray, wear_gray, mm_px,
                     blur=5, area_thresh_px=200, morph_ksize=7):
    # enhance V channel contrast
    ref_hsv = cv2.cvtColor(ref_color, cv2.COLOR_BGR2HSV)
    wear_hsv = cv2.cvtColor(wear_color, cv2.COLOR_BGR2HSV)
    v_ref  = cv2.GaussianBlur(ref_hsv[:,:,2], (blur, blur), 0)
    v_wear = cv2.GaussianBlur(wear_hsv[:,:,2], (blur, blur), 0)
    diff_v = cv2.subtract(v_wear, v_ref)
    # stretch
    mn, mx = diff_v.min(), diff_v.max()
    if mx > mn:
        diff_v = ((diff_v - mn) * (255.0/(mx - mn))).astype(np.uint8)
    # Otsu on V-diff
    _, thr = cv2.threshold(diff_v, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    # morphology
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (morph_ksize, morph_ksize))
    clean = cv2.morphologyEx(thr, cv2.MORPH_CLOSE, kernel, iterations=3)
    clean = cv2.morphologyEx(clean, cv2.MORPH_OPEN,  kernel, iterations=2)
    # label & area
    lbl = label(clean)
    mask = np.zeros_like(clean)
    total_area_px = 0
    for reg in regionprops(lbl):
        if reg.area < area_thresh_px:
            continue
        coords = reg.coords
        mask[coords[:,0], coords[:,1]] = 255
        total_area_px += reg.area
    area_mm2 = total_area_px * mm_px**2
    # annotate
    cont,_ = cv2.findContours(mask.astype(np.uint8), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    ov = wear_color.copy()
    cv2.drawContours(ov, cont, -1, (0,0,255), 2)
    out = cv2.addWeighted(wear_color,1.0,ov,0.4,0)
    cv2.putText(out, f"A_top={area_mm2:.2f}mm2", (10,30), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)
    return mask, area_mm2, out

# ------------------------------------------
# Main pipeline: side + top
# ------------------------------------------
def process_wear(ref_side, wear_side, ref_top, wear_top,
                 real_w_side_mm, real_w_top_mm, out_prefix="RESULT"):
    # calibration
    mm_s = get_mm_per_pixel(ref_side, real_width_mm=real_w_side_mm)
    mm_t = get_mm_per_pixel(ref_top,  real_width_mm=real_w_top_mm)
    # side view
    rc_s, rg_s = read_and_preprocess(ref_side)
    wc_s, wg_s = read_and_preprocess(wear_side)
    al_s = align_images(rg_s, wg_s)
    mask_s, area_s, davg_s, dmax_s, vol_s, an_s = detect_wear_side(rg_s, al_s, wc_s, mm_s)
    cv2.imwrite(f"{out_prefix}_side.png", an_s)
    # top view
    rc_t, rg_t = read_and_preprocess(ref_top)
    wc_t, wg_t = read_and_preprocess(wear_top)
    al_t = align_images(rg_t, wg_t)
    mask_t, area_t, an_t = detect_wear_top(rc_t, wc_t, rg_t, al_t, mm_t)
    cv2.imwrite(f"{out_prefix}_top.png", an_t)
    # results
    print(f"[SIDE] A={area_s:.2f}mm², Davg={davg_s:.3f}mm, Dmax={dmax_s:.3f}mm, V={vol_s:.2f}mm³")
    print(f"[TOP ] A={area_t:.2f}mm²")
    return {
        'side': {'area_mm2': area_s, 'avg_depth_mm': davg_s, 'max_depth_mm': dmax_s, 'volume_mm3': vol_s},
        'top':  {'area_mm2': area_t}
    }

# Example usage:
res = process_wear("images/ref1.png","images/wear1.png","images/top_ref.jpg","images/top_wear.jpg",1.75,5.0)
# print(res)
