#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    string input_path = "images/IMG_20251118_142320.jpg";
    string output_path = "results/task3_black_bg_cpp.jpg";
    // 读取图片
    Mat original_image = imread(input_path);
    if (original_image.empty()) {
        cout << "错误: 无法读取图片 " << input_path << endl;
        return -1;
    }
    
    cout << "原始图片尺寸: " << original_image.cols << " x " << original_image.rows << endl;
    cout << "通道数: " << original_image.channels() << endl;
    
    // 定义白色的BGR范围
    Scalar lower_white(200, 200, 200);  // B, G, R 都大于200
    Scalar upper_white(255, 255, 255);  // B, G, R 最大值255
    
    // 创建白色区域的掩码
    Mat mask;
    inRange(original_image, lower_white, upper_white, mask);
    
    // 复制原图
    Mat result = original_image.clone();
    
    // 将白色区域变成黑色
    result.setTo(Scalar(0, 0, 0), mask);  //调成黑色
    
    // 保存结果
    bool save_success = imwrite(output_path, result);
    if (!save_success) {
        cout << "错误: 无法保存图片 " << output_path << endl;
        return -1;
    }
    // 计算并显示处理信息
    int white_pixels = countNonZero(mask);
    int total_pixels = original_image.rows * original_image.cols;
    double white_percentage = (white_pixels * 100.0) / total_pixels;
    
    cout << "TASK3完成: 黑色背景图已保存为 " << output_path << endl;
    cout << "检测到的白色像素: " << white_pixels << " / " << total_pixels 
         << " (" << white_percentage << "%)" << endl;
    
    return 0;
}