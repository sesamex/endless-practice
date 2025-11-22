import cv2
import numpy as np
import os

def detect_text_contours_optimized():
    
    input_path = '../images/IMG_20251118_142320.jpg'
    output_path = '../results/task5_contours_optimized.jpg'
    
    os.makedirs('../results', exist_ok=True)
    
    # 读取图片
    img = cv2.imread(input_path)
    if img is None:
        print("错误: 无法读取图片")
        return
    
    print(f"原始图片尺寸: {img.shape}")
    
    # 步骤1: 转换为灰度图
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    
    # 步骤2: 高斯模糊，减少噪点
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)
    
    # 步骤3: 二值化 - 调整参数
    binary = cv2.adaptiveThreshold(
        blurred, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, 
        cv2.THRESH_BINARY_INV, 15, 5  # 调整了块大小和常数
    )
    
    # 步骤4: 形态学操作 - 先腐蚀后膨胀（开运算）去除小噪点
    kernel = np.ones((2, 2), np.uint8)
    cleaned = cv2.morphologyEx(binary, cv2.MORPH_OPEN, kernel)
    
    # 步骤5: 膨胀操作连接文字
    kernel2 = np.ones((3, 3), np.uint8)
    dilated = cv2.dilate(cleaned, kernel2, iterations=2)
    
    # 步骤6: 查找轮廓
    contours, hierarchy = cv2.findContours(
        dilated, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE
    )
    
    # 步骤7: 过滤小轮廓（只保留面积较大的轮廓，可能是文字）
    min_area = 100  
    filtered_contours = []
    
    for contour in contours:
        area = cv2.contourArea(contour)
        if area > min_area:
            filtered_contours.append(contour)
    
    print(f"找到 {len(contours)} 个轮廓，过滤后剩 {len(filtered_contours)} 个")
    
    # 步骤8: 在原图上用红色绘制过滤后的轮廓
    result = img.copy()
    cv2.drawContours(result, filtered_contours, -1, (0, 0, 255), 2)  # 红色轮廓
    
    # 保存结果
    cv2.imwrite(output_path, result)
    
    print("TASK5优化版完成!")
    print(f"结果: {output_path}")
    print(f"过滤掉了 {len(contours) - len(filtered_contours)} 个小噪点")

if __name__ == "__main__":
    detect_text_contours_optimized()