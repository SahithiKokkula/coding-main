import cv2
import numpy as np

def generate_synthetic_images():
    """
    Generates three synthetic images to simulate a reference image and two worn samples.
    
    - The reference image (tool_a.jpg) is a plain gray background with a rectangular "tool" shape.
    - Worn sample B (tool_b.jpg) is the reference with a circular worn-out region.
    - Worn sample C (tool_c.jpg) is the reference with an elliptical worn-out region.
    """
    # Set image dimensions.
    width, height = 400, 300

    # ----------------------
    # Generate Reference Image (tool_a.jpg)
    # ----------------------
    # Create a uniform light-gray background.
    ref_img = np.full((height, width, 3), 220, dtype=np.uint8)
    # Draw a darker gray rectangle representing the tool.
    cv2.rectangle(ref_img, (50, 50), (350, 250), (180, 180, 180), -1)
    # Save the reference image.
    cv2.imwrite("tool_a.jpg", ref_img)

    # ----------------------
    # Generate Worn Sample B (tool_b.jpg)
    # ----------------------
    # Start with the reference image.
    wear_b = ref_img.copy()
    # Draw a circular region to simulate wear (darker region).
    cv2.circle(wear_b, (200, 150), 30, (80, 80, 80), -1)
    cv2.imwrite("tool_b.jpg", wear_b)

    # ----------------------
    # Generate Worn Sample C (tool_c.jpg)
    # ----------------------
    # Start with the reference image.
    wear_c = ref_img.copy()
    # Draw an elliptical region to simulate wear.
    cv2.ellipse(wear_c, (250, 170), (40, 20), 30, 0, 360, (100, 100, 100), -1)
    cv2.imwrite("tool_c.jpg", wear_c)

    print("[INFO] Synthetic images generated and saved as:")
    print(" - tool_a.jpg (Reference image)")
    print(" - tool_b.jpg (Worn sample B)")
    print(" - tool_c.jpg (Worn sample C)")

if __name__ == "__main__":
    generate_synthetic_images()
