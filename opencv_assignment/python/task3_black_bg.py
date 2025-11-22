import cv2
import numpy as np
import os

def white_to_black_simple():
    
    input_path = '../images/IMG_20251118_142320.jpg'
    output_path = '../results/task3_final.jpg'
    
    img = cv2.imread(input_path)
    if img is None:
        print("错误: 无法读取图片")
        return
    
    # 使用适中的阈值220
    lower_white = np.array([220, 220, 220])
    upper_white = np.array([255, 255, 255])
    
    mask = cv2.inRange(img, lower_white, upper_white)
    result = img.copy()
    result[mask > 0] = [0, 0, 0]
    
    cv2.imwrite(output_path, result)
    print(f"TASK3完成: 最终结果保存为 {output_path}")
    
    # 只显示基本信息
    white_pixels = np.sum(mask > 0)
    total_pixels = img.shape[0] * img.shape[1]
    print(f"处理的白色像素: {white_pixels}/{total_pixels}")

if __name__ == "__main__":
    white_to_black_simple()