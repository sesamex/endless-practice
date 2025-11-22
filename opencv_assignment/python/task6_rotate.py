import cv2
import numpy as np
import os

def rotate_image_45():
    
    input_path = '../images/IMG_20251118_142320.jpg'
    output_path = '../results/task6_rotated.jpg'
    
    os.makedirs('../results', exist_ok=True)
    
    # 读取图片
    img = cv2.imread(input_path)
    if img is None:
        print("错误: 无法读取图片")
        return
    
    print(f"原始图片尺寸: {img.shape}")
    
    # 获取图片中心点
    height, width = img.shape[:2]
    center = (width // 2, height // 2)
    print(f"旋转中心: {center}")
    
    # 计算旋转矩阵
    # 参数：中心点，旋转角度，缩放比例
    rotation_matrix = cv2.getRotationMatrix2D(center, 45, 1.0)
    print("旋转矩阵计算完成")
    
    # 计算旋转后的图片尺寸
    cos_val = np.abs(rotation_matrix[0, 0])
    sin_val = np.abs(rotation_matrix[0, 1])
    
    new_width = int((height * sin_val) + (width * cos_val))
    new_height = int((height * cos_val) + (width * sin_val))
    
    print(f"新图片尺寸: {new_width} x {new_height}")
    
    # 调整旋转矩阵，考虑图片中心移动
    rotation_matrix[0, 2] += (new_width / 2) - center[0]
    rotation_matrix[1, 2] += (new_height / 2) - center[1]
    
    # 执行旋转
    rotated_img = cv2.warpAffine(
        img, 
        rotation_matrix, 
        (new_width, new_height),
        flags=cv2.INTER_LINEAR,
        borderMode=cv2.BORDER_CONSTANT,
        borderValue=(255, 255, 255)  # 白色背景
    )
    
    # 保存结果
    cv2.imwrite(output_path, rotated_img)
    
    print("TASK6完成: 图片旋转45度完成")
    print(f"结果保存为: {output_path}")
    print(f"原始尺寸: {width} x {height}")
    print(f"旋转后尺寸: {new_width} x {new_height}")

if __name__ == "__main__":
    rotate_image_45()