import cv2
import numpy as np
import os
import matplotlib.pyplot as plt
from skimage import measure
import argparse

def capture_tool_image(camera_index=0):
    """
    Capture an image from the connected camera.
    
    Args:
        camera_index: Index of the camera device to use.
        
    Returns:
        Captured image or None if capture failed.
    """
    # Initialize camera
    cap = cv2.VideoCapture(camera_index)
    
    if not cap.isOpened():
        print("Error: Could not open camera")
        return None
    
    # Set camera parameters for optimal image quality
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1920)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 1080)
    cap.set(cv2.CAP_PROP_BRIGHTNESS, 150)
    
    # Capture frame
    ret, frame = cap.read()
    
    # Release camera
    cap.release()
    
    if not ret:
        print("Error: Could not capture image")
        return None
    
    return frame

def preprocess_image(image):
    """
    Preprocess the input image for tool edge detection.
    
    Args:
        image: Input BGR image.
        
    Returns:
        Tuple of (grayscale image, binary image).
    """
    # Convert to grayscale
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    
    # Apply Gaussian blur to reduce noise
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)
    
    # Apply adaptive thresholding
    binary = cv2.adaptiveThreshold(
        blurred, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, 
        cv2.THRESH_BINARY_INV, 11, 2
    )
    
    # Apply morphological operations to clean up the binary image
    kernel = np.ones((3, 3), np.uint8)
    binary = cv2.morphologyEx(binary, cv2.MORPH_CLOSE, kernel)
    binary = cv2.morphologyEx(binary, cv2.MORPH_OPEN, kernel)
    
    return gray, binary

def calibrate_with_aruco(image, marker_size_mm=20.0):
    MARKER_SIZE_MM = marker_size_mm
    """
    Calibrate the system using Aruco markers to determine pixel-to-mm ratio.
    
    Args:
        image: Input image containing an Aruco marker of known size.
        
    Returns:
        Pixels per millimeter ratio or None if calibration failed.
    """
    # Load the predefined dictionary
    aruco_dict = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_6X6_250)
    parameters = cv2.aruco.DetectorParameters_create()
    
    # Detect markers
    corners, ids, _ = cv2.aruco.detectMarkers(image, aruco_dict, parameters=parameters)
    
    if ids is None or len(ids) == 0:
        print("No Aruco marker detected")
        return None
    
    # The Aruco marker has known dimensions (e.g., 20x20mm)
    MARKER_SIZE_MM = 20.0
    
    # Calculate pixels per mm
    marker_corners = corners[0][0]
    top_left = marker_corners[0]
    top_right = marker_corners[1]
    
    # Calculate marker width in pixels
    marker_width_pixels = np.linalg.norm(top_right - top_left)
    
    # Calculate pixels per mm
    pixels_per_mm = marker_width_pixels / MARKER_SIZE_MM
    
    print(f"Calibration: {pixels_per_mm:.2f} pixels/mm")
    
    return pixels_per_mm


def extract_tool_roi(image, binary_image):
    """
    Extract the region of interest containing the cutting tool and detect the cutting edge.
    
    Args:
        image: Original input image.
        binary_image: Binary preprocessed image.
        
    Returns:
        Tuple of (ROI image, cutting edge parameters).
    """
    # Convert cutting edge coordinates to absolute position
    cutting_edge += [x, y]  # Add ROI offset to maintain global coordinates
    # Find contours in the binary image
    contours, _ = cv2.findContours(binary_image, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    if not contours:
        print("No contours found in the binary image")
        return None, None
    
    # Filter contours based on area to find the tool
    tool_contour = max(contours, key=cv2.contourArea)
    
    # Create a mask for the tool
    mask = np.zeros_like(binary_image)
    cv2.drawContours(mask, [tool_contour], -1, 255, -1)
    
    # Extract the tool edge
    # Use the Canny edge detector to find edges
    edges = cv2.Canny(mask, 50, 150)
    
    # Use Hough Line Transform to detect straight lines
    lines = cv2.HoughLinesP(edges, 1, np.pi/180, threshold=50, 
                           minLineLength=50, maxLineGap=10)
    
    # Extract the cutting edge region (Region B according to ISO 3685:1993)
    # For demonstration, we'll assume the longest line is the cutting edge
    if lines is not None:
        max_line_length = 0
        cutting_edge = None
        
        for line in lines:
            x1, y1, x2, y2 = line[0]
            length = np.sqrt((x2 - x1)**2 + (y2 - y1)**2)
            
            if length > max_line_length:
                max_line_length = length
                cutting_edge = line[0]
        
        if cutting_edge is None:
            print("Could not detect a cutting edge")
            return None, None
            
        # Define ROI around the cutting edge
        x1, y1, x2, y2 = cutting_edge
        padding = 50  # Add padding around the edge
        
        # Get the bounding box of the tool contour
        x, y, w, h = cv2.boundingRect(tool_contour)
        
        # Extract the ROI from the original image
        roi = image[max(0, y):min(y+h, image.shape[0]), 
                   max(0, x):min(x+w, image.shape[1])]
        
        return roi, cutting_edge
    
    print("No lines detected in the edge image")
    return None, None

def detect_wear_region(reference_image, worn_image):
    """
    Detect wear region by comparing reference and worn tool images.
    Implements a simplified version of the grayscale image probability (GIP) algorithm.
    
    Args:
        reference_image: Image of the new (unworn) tool.
        worn_image: Image of the worn tool.
        
    Returns:
        Tuple of (wear mask, wear contours).
    """
    # Make sure both images have the same size
    if reference_image.shape != worn_image.shape:
        worn_image = cv2.resize(worn_image, (reference_image.shape[1], reference_image.shape[0]))
    
    # Convert to grayscale if not already
    if len(reference_image.shape) > 2:
        reference_gray = cv2.cvtColor(reference_image, cv2.COLOR_BGR2GRAY)
    else:
        reference_gray = reference_image
        
    if len(worn_image.shape) > 2:
        worn_gray = cv2.cvtColor(worn_image, cv2.COLOR_BGR2GRAY)
    else:
        worn_gray = worn_image
    
    # Apply histogram equalization to both images
    reference_eq = cv2.equalizeHist(reference_gray)
    worn_eq = cv2.equalizeHist(worn_gray)
    
    # Calculate absolute difference between images
    diff = cv2.absdiff(reference_eq, worn_eq)
    
    # Apply threshold to get binary wear mask
    _, wear_mask = cv2.threshold(diff, 0, 255, cv2.THRESH_BINARY+cv2.THRESH_OTSU)
    
    # Remove noise using morphological operations
    kernel = np.ones((3, 3), np.uint8)
    wear_mask = cv2.morphologyEx(wear_mask, cv2.MORPH_OPEN, kernel)
    wear_mask = cv2.morphologyEx(wear_mask, cv2.MORPH_CLOSE, kernel)
    
    # Find contours of wear regions
    contours, _ = cv2.findContours(wear_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    # Filter contours based on area to remove small noise
    min_area = 100  # Minimum area threshold
    wear_contours = [cnt for cnt in contours if cv2.contourArea(cnt) > min_area]
    
    return wear_mask, wear_contours

def calculate_wear_depth(reference_edge, wear_contours, pixels_per_mm):
    """
    Calculate the depth of wear by finding the maximum distance
    from the reference edge to the wear contour.
    
    Args:
        reference_edge: Parameters of the reference cutting edge.
        wear_contours: List of contours representing wear regions.
        pixels_per_mm: Calibration factor (pixels per millimeter).
        
    Returns:
        Tuple of (maximum wear depth in mm, point of maximum depth).
    """
    if not wear_contours:
        print("No wear contours detected")
        return 0, None
        
    # Extract reference edge line parameters
    x1, y1, x2, y2 = reference_edge
    
    # Line equation: ax + by + c = 0
    a = y2 - y1
    b = x1 - x2
    c = x2*y1 - x1*y2
    
    # Normalize to get unit normal vector
    normal_length = np.sqrt(a*a + b*b)
    if normal_length == 0:
        print("Invalid reference edge (zero length)")
        return 0, None
        
    a /= normal_length
    b /= normal_length
    c /= normal_length
    
    max_depth = 0
    max_depth_point = None
    
    # For each wear contour, find the maximum distance to the reference edge
    for contour in wear_contours:
        for point in contour:
            x, y = point[0]
            # Distance from point to line
            distance = abs(a*x + b*y + c)
            
            if distance > max_depth:
                max_depth = distance
                max_depth_point = (x, y)
    
    # Convert from pixels to millimeters
    max_depth_mm = max_depth / pixels_per_mm
    
    return max_depth_mm, max_depth_point


def visualize_results(original_image, reference_edge, wear_contours, max_depth_point, max_depth_mm):
    """
    Visualize the wear analysis results on the original image.
    
    Args:
        original_image: Original image of the worn tool.
        reference_edge: Parameters of the reference cutting edge.
        wear_contours: List of contours representing wear regions.
        max_depth_point: Point of maximum wear depth.
        max_depth_mm: Maximum wear depth in millimeters.
        
    Returns:
        Image with visualized results.
    """
    # Create a copy of the original image for visualization
    result_image = original_image.copy()
    
    # Draw the reference edge
    x1, y1, x2, y2 = reference_edge
    cv2.line(result_image, (x1, y1), (x2, y2), (0, 255, 0), 2)
    
    # Draw wear contours
    cv2.drawContours(result_image, wear_contours, -1, (0, 0, 255), 2)
    
    # Draw the maximum depth point
    if max_depth_point is not None:
        cv2.circle(result_image, max_depth_point, 5, (255, 0, 0), -1)
        
        # Draw a line showing the depth measurement
        # Calculate the nearest point on the reference edge
        a = y2 - y1
        b = x1 - x2
        c = x2*y1 - x1*y2
        
        x0, y0 = max_depth_point
        # Project point onto line
        x_proj = (b*(b*x0 - a*y0) - a*c) / (a*a + b*b)
        y_proj = (a*(-b*x0 + a*y0) - b*c) / (a*a + b*b)
        
        cv2.line(result_image, (int(x_proj), int(y_proj)), max_depth_point, (255, 255, 0), 2)
        
        # Add text with measurement
        cv2.putText(result_image, f"Depth: {max_depth_mm:.3f} mm", 
                   (max_depth_point[0] + 10, max_depth_point[1]), 
                   cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 0), 2)
    
    return result_image


def load_unet_model(model_path):
    """
    Load a pre-trained U-Net model for tool wear segmentation.
    This is a placeholder function. In a real implementation, you would 
    load a model from TensorFlow, PyTorch, or another deep learning framework.
    
    Args:
        model_path: Path to the saved model.
        
    Returns:
        Loaded model or None.
    """
    try:
        print(f"Loading U-Net model from {model_path}")
        # In a real implementation, you would use something like:
        # from tensorflow.keras.models import load_model
        # model = load_model(model_path)
        # return model
        return None
    except Exception as e:
        print(f"Error loading model: {e}")
        return None

def segment_wear_with_unet(model, image):
    """
    Use U-Net model to segment tool wear regions.
    This is a placeholder function. In a real implementation, you would 
    use the model to predict wear regions.
    
    Args:
        model: Loaded U-Net model.
        image: Input image.
        
    Returns:
        Binary mask of wear regions.
    """
    # Preprocess image for the model
    # Resize to model's expected input size
    resized = cv2.resize(image, (256, 256))
    
    # Normalize pixel values
    normalized = resized / 255.0
    
    # For demonstration, we'll return a placeholder mask
    # In a real implementation, you would use:
    # input_image = np.expand_dims(normalized, axis=0)
    # prediction = model.predict(input_image)
    # wear_mask = (prediction[0, :, :, 0] > 0.5).astype(np.uint8) * 255
    # wear_mask = cv2.resize(wear_mask, (image.shape[1], image.shape[0]))
    
    wear_mask = np.zeros((image.shape[0], image.shape[1]), dtype=np.uint8)
    
    return wear_mask


def main():
    """
    Main function to run the tool wear detection system.
    """
    # Parse command-line arguments
    parser = argparse.ArgumentParser(description='Tool Wear Depth Detection')
    parser.add_argument('--reference', type=str, required=True, help='Path to reference tool image')
    parser.add_argument('--worn', type=str, required=True, help='Path to worn tool image')
    parser.add_argument('--output', type=str, default='tool_wear_analysis.jpg', help='Output image path')
    parser.add_argument('--use-unet', action='store_true', help='Use U-Net model for segmentation')
    parser.add_argument('--model-path', type=str, default='unet_model.h5', help='Path to U-Net model (if using --use-unet)')
    
    args = parser.parse_args()
    
    # 1. Load images
    reference_image_path = args.reference
    worn_image_path = args.worn
    
    reference_image = cv2.imread(reference_image_path)
    worn_image = cv2.imread(worn_image_path)
    
    if reference_image is None or worn_image is None:
        print("Error: Could not load images")
        return
    
    # 2. Preprocess images
    reference_gray, reference_binary = preprocess_image(reference_image)
    worn_gray, worn_binary = preprocess_image(worn_image)
    
    # 3. Calibrate using Aruco marker
    pixels_per_mm = calibrate_with_aruco(worn_image)
    
    if pixels_per_mm is None:
        print("Warning: Could not calibrate with Aruco marker. Using default value of 100 pixels/mm")
        pixels_per_mm = 100.0  # Default value
    
    # 4. Extract ROI and cutting edge
    reference_roi, reference_edge = extract_tool_roi(reference_image, reference_binary)
    
    if reference_roi is None or reference_edge is None:
        print("Error: Could not extract reference tool ROI or cutting edge")
        return
        
    worn_roi, _ = extract_tool_roi(worn_image, worn_binary)
    
    if worn_roi is None:
        print("Error: Could not extract worn tool ROI")
        return
    
    # 5. Detect wear regions
    if args.use_unet:
        # Load U-Net model
        model = load_unet_model(args.model_path)
        if model is not None:
            # Use U-Net for wear segmentation
            wear_mask = segment_wear_with_unet(model, worn_roi)
            # Find contours in the wear mask
            contours, _ = cv2.findContours(wear_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
            # Filter contours based on area
            min_area = 100
            wear_contours = [cnt for cnt in contours if cv2.contourArea(cnt) > min_area]
        else:
            # Fall back to traditional method
            wear_mask, wear_contours = detect_wear_region(reference_roi, worn_roi)
    else:
        # Use traditional method for wear detection
        wear_mask, wear_contours = detect_wear_region(reference_roi, worn_roi)
    
    # 6. Calculate wear depth
    max_depth_mm, max_depth_point = calculate_wear_depth(reference_edge, wear_contours, pixels_per_mm)
    
    # 7. Visualize results
    result_image = visualize_results(
        worn_image, reference_edge, wear_contours, 
        max_depth_point, max_depth_mm
    )
    
    # 8. Save results
    cv2.imwrite(args.output, result_image)
    
    # Display the result
    plt.figure(figsize=(12, 10))
    plt.imshow(cv2.cvtColor(result_image, cv2.COLOR_BGR2RGB))
    plt.title(f"Tool Wear Analysis - Max Depth: {max_depth_mm:.3f} mm")
    plt.axis('off')
    plt.show()
    
    # Report results
    print(f"Maximum wear depth: {max_depth_mm:.3f} mm")
    print(f"Result saved to: {args.output}")

if __name__ == "__main__":
    main()
