import cv2
import numpy as np
import os

def single_rgb_channels_simple():
   
    input_path = '../images/IMG_20251118_142320.jpg'
    
    os.makedirs('../results', exist_ok=True)
    
    img = cv2.imread(input_path)
    if img is None:
        print(f"错误: 无法读取图片 {input_path}")
        return
    
    # 分离BGR通道
    blue_ch, green_ch, red_ch = cv2.split(img)
    zeros = np.zeros_like(blue_ch)
    
    # 只生成彩色单通道图像
    blue_only = cv2.merge([blue_ch, zeros, zeros])
    green_only = cv2.merge([zeros, green_ch, zeros])
    red_only = cv2.merge([zeros, zeros, red_ch])
    
    cv2.imwrite('../results/task4_blue.jpg', blue_only)
    cv2.imwrite('../results/task4_green.jpg', green_only)
    cv2.imwrite('../results/task4_red.jpg', red_only)
    
    print("TASK4完成: 单通道彩色图已保存")
    print("蓝色通道: task4_blue.jpg")
    print("绿色通道: task4_green.jpg")
    print("红色通道: task4_red.jpg")

if __name__ == "__main__":
    single_rgb_channels_simple()