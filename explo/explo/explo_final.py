import cv2
import numpy as np
from skimage.measure import label, regionprops

# ------------------------------------------
# Calibration: compute mm-per-pixel
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
# Preprocessing: grayscale, CLAHE, equalize, blur
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
# Alignment: SIFT with ORB fallback
# ------------------------------------------
def align_images(ref_gray, target_gray, min_matches=8):
    try:
        detector = cv2.SIFT_create()
        norm = cv2.NORM_L2
    except Exception:
        detector = cv2.ORB_create(5000)
        norm = cv2.NORM_HAMMING
    kp1, des1 = detector.detectAndCompute(ref_gray, None)
    kp2, des2 = detector.detectAndCompute(target_gray, None)
    if des1 is None or des2 is None:
        return target_gray
    matcher = cv2.BFMatcher(norm)
    matches = matcher.knnMatch(des1, des2, k=2)
    good = [m for m,n in matches if m.distance < 0.75*n.distance]
    if len(good) < min_matches:
        return target_gray
    src = np.float32([kp1[m.queryIdx].pt for m in good]).reshape(-1,1,2)
    dst = np.float32([kp2[m.trainIdx].pt for m in good]).reshape(-1,1,2)
    H, _ = cv2.findHomography(dst, src, cv2.RANSAC, 5.0)
    aligned = cv2.warpPerspective(target_gray, H, (ref_gray.shape[1], ref_gray.shape[0]))
    return aligned

# ------------------------------------------
# Side-view wear detection: combine gray + V-diff
# ------------------------------------------
def detect_wear_side(ref_color, wear_color, ref_gray, wear_gray, mm_px,
                      blur=5, area_thresh_px=200, morph_ksize=5):
    # 1) Grayscale diff
    diff_gray = cv2.absdiff(ref_gray, wear_gray)
    diff_gray = cv2.GaussianBlur(diff_gray, (blur, blur), 0)
    mn, mx = diff_gray.min(), diff_gray.max()
    if mx > mn:
        diff_gray = ((diff_gray - mn) * (255.0/(mx - mn))).astype(np.uint8)
    _, thr_gray = cv2.threshold(diff_gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

    # 2) V-channel diff
    hsv_ref  = cv2.cvtColor(ref_color,  cv2.COLOR_BGR2HSV)
    hsv_wear = cv2.cvtColor(wear_color, cv2.COLOR_BGR2HSV)
    v_ref  = cv2.GaussianBlur(hsv_ref[:,:,2],  (blur,blur), 0)
    v_wear = cv2.GaussianBlur(hsv_wear[:,:,2], (blur,blur), 0)
    diff_v = cv2.subtract(v_wear, v_ref)
    mnv, mxv = diff_v.min(), diff_v.max()
    if mxv > mnv:
        diff_v = ((diff_v - mnv)*(255.0/(mxv-mnv))).astype(np.uint8)
    _, thr_v = cv2.threshold(diff_v, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

    # Combine & clean
    mask = cv2.bitwise_or(thr_gray, thr_v)
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (morph_ksize, morph_ksize))
    mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel, iterations=2)
    mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN,  kernel, iterations=1)

    # Measure and integrate
    lbl = label(mask)
    total_area_px = 0
    volume_px3 = 0
    max_depth_px = 0
    for reg in regionprops(lbl, intensity_image=diff_gray):
        if reg.area < area_thresh_px:
            continue
        total_area_px += reg.area
        depths = reg.intensity_image[reg.image].flatten().astype(np.float32)
        volume_px3 += depths.sum()
        max_depth_px = max(max_depth_px, depths.max())

    area_mm2   = total_area_px * mm_px**2
    max_d_mm   = max_depth_px     * mm_px
    vol_mm3    = volume_px3       * (mm_px**3)
    avg_d_mm   = vol_mm3 / area_mm2 if area_mm2 else 0

    # Annotate
    contours,_ = cv2.findContours(mask.astype(np.uint8), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    overlay = wear_color.copy()
    cv2.drawContours(overlay, contours, -1, (0,255,0), 2)
    annotated = cv2.addWeighted(wear_color, 1.0, overlay, 0.4, 0)
    cv2.putText(annotated, f"Area={area_mm2:.2f}mm²", (10,30), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)
    cv2.putText(annotated, f"AvgDepth={avg_d_mm:.3f}mm", (10,60), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)
    cv2.putText(annotated, f"MaxDepth={max_d_mm:.3f}mm", (10,90), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)
    cv2.putText(annotated, f"Volume={vol_mm3:.2f}mm³", (10,120), cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)

    return mask, area_mm2, avg_d_mm, max_d_mm, vol_mm3, annotated

# ------------------------------------------
# Top-view wear detection: unchanged
# ------------------------------------------
def detect_wear_top(ref_color, wear_color, ref_gray, wear_gray, mm_px,
                     blur=5, area_thresh_px=200, morph_ksize=7):
    # [existing V-channel+Otsu logic preserved]
    hsv_ref  = cv2.cvtColor(ref_color,  cv2.COLOR_BGR2HSV)
    hsv_wear = cv2.cvtColor(wear_color, cv2.COLOR_BGR2HSV)
    v_ref  = cv2.GaussianBlur(hsv_ref[:,:,2],  (blur,blur), 0)
    v_wear = cv2.GaussianBlur(hsv_wear[:,:,2], (blur,blur), 0)
    diff_v = cv2.subtract(v_wear, v_ref)
    mn, mx = diff_v.min(), diff_v.max()
    diff_v = ((diff_v - mn)*255.0/(mx-mn)).astype(np.uint8)
    _, thr = cv2.threshold(diff_v, 0, 255, cv2.THRESH_BINARY+cv2.THRESH_OTSU)
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (morph_ksize,morph_ksize))
    mask = cv2.morphologyEx(thr, cv2.MORPH_CLOSE, kernel, iterations=3)
    mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN,  kernel, iterations=2)
    lbl = label(mask)
    total_px= sum(reg.area for reg in regionprops(lbl))
    area_mm2 = total_px * mm_px**2
    contours,_ = cv2.findContours(mask.astype(np.uint8), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    overlay = wear_color.copy()
    cv2.drawContours(overlay, contours, -1, (0,0,255),2)
    annotated = cv2.addWeighted(wear_color,1.0,overlay,0.4,0)
    cv2.putText(annotated, f"TopArea={area_mm2:.2f}mm²",(10,30),cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,255),2)
    return mask, area_mm2, annotated

# ------------------------------------------
# Main: process both views
# ------------------------------------------
def process_wear(ref_side, wear_side, ref_top, wear_top,
                 real_w_side_mm, real_w_top_mm, out_prefix="RESULT"):
    # calibration
    mm_side = get_mm_per_pixel(ref_side, real_width_mm=real_w_side_mm)
    mm_top  = get_mm_per_pixel(ref_top,  real_width_mm=real_w_top_mm)

    # side view
    ref_c_s, ref_g_s = read_and_preprocess(ref_side)
    wear_c_s, wear_g_s = read_and_preprocess(wear_side)
    aligned_s = align_images(ref_g_s, wear_g_s)
    mask_s, area_s, avg_s, max_s, vol_s, ann_s = detect_wear_side(
        ref_c_s, wear_c_s, ref_g_s, aligned_s, mm_side)
    cv2.imwrite(f"{out_prefix}_side.png", ann_s)

    # top view
    ref_c_t, ref_g_t = read_and_preprocess(ref_top)
    wear_c_t, wear_g_t = read_and_preprocess(wear_top)
    aligned_t = align_images(ref_g_t, wear_g_t)
    mask_t, area_t, ann_t = detect_wear_top(
        ref_c_t, wear_c_t, ref_g_t, aligned_t, mm_top)
    cv2.imwrite(f"{out_prefix}_top.png", ann_t)

    # results
    print(f"[SIDE] Area={area_s:.2f}mm², AvgD={avg_s:.3f}mm, MaxD={max_s:.3f}mm, Vol={vol_s:.2f}mm³")
    print(f"[TOP ] Area={area_t:.2f}mm²")

        # Display the final annotated results
    cv2.imshow("Top View Wear Detection", ann_s)
    cv2.imshow("Side View Wear Detection", ann_t)

    # Wait for a key press and close all windows
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    return {
        'side': {'area_mm2': area_s, 'avg_depth_mm': avg_s, 'max_depth_mm': max_s, 'volume_mm3': vol_s},
        'top':  {'area_mm2': area_t}
    }

# Example usage:
res = process_wear("images/ref1.png","images/wear1.png","images/top_ref.jpg","images/top_wear.jpg",1.75,5.0)
print(res)
