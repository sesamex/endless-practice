import cv2
import os

def convert_to_grayscale():    
    #将图片转为灰度图    
    #读取原始图片
    input_path='images/IMG_20251118_142320.jpg'    
    output_path='results/task2_gray.jpg'
    
     # 确保输出目录存在    
    os.makedirs('results', exist_ok=True)
            
    # 读取图片    
    img = cv2.imread(input_path)    
    if img is None:      
      print(f"错误: 无法读取图片 {input_path}")        
      return        
      # 转换为灰度图
          
    gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
            
    # 保存结果    
    cv2.imwrite(output_path, gray_img)    
    print(f"TASK2完成: 灰度图已保存为 {output_path}")
            
    # 显示图片信息    
    print(f"原始图片尺寸: {img.shape}")    
    print(f"灰度图尺寸: {gray_img.shape}")
if __name__ == "__main__":
    convert_to_grayscale()