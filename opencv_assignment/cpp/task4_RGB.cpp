#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main() {
    string input_path = "images/IMG_20251118_142320.jpg";  
    
    // 读取图片
    Mat original_image = imread(input_path);
    if (original_image.empty()) {
        cout << "错误: 无法读取图片 " << input_path << endl;
        return -1;
    }
    
    cout << "原始图片尺寸: " << original_image.cols << " x " << original_image.rows << endl;
    cout << "通道数: " << original_image.channels() << endl;
    
    // 分离BGR通道
    vector<Mat> channels;
    split(original_image, channels);
    // channels[0] = Blue, channels[1] = Green, channels[2] = Red
    
    // 创建全零矩阵（黑色背景）
    Mat zeros = Mat::zeros(original_image.size(), CV_8UC1);
    
    // 准备合并的通道向量
    vector<Mat> blue_channels, green_channels, red_channels;
    Mat blue_only, green_only, red_only;
    
    // 蓝色通道：只保留蓝色，其他为0
    blue_channels = {channels[0], zeros, zeros};
    merge(blue_channels, blue_only);
    
    // 绿色通道：只保留绿色，其他为0
    green_channels = {zeros, channels[1], zeros};
    merge(green_channels, green_only);
    
    // 红色通道：只保留红色，其他为0
    red_channels = {zeros, zeros, channels[2]};
    merge(red_channels, red_only);
    
    // 保存结果
    imwrite("results/task4_blue_cpp.jpg", blue_only);
    imwrite("results/task4_green_cpp.jpg", green_only);
    imwrite("results/task4_red_cpp.jpg", red_only);
    
    cout << "TASK4完成(C++版本): 单通道彩色图已保存" << endl;
    cout << "生成的图片:" << endl;
    cout << "- task4_blue_cpp.jpg   : 只显示蓝色通道" << endl;
    cout << "- task4_green_cpp.jpg  : 只显示绿色通道" << endl;
    cout << "- task4_red_cpp.jpg    : 只显示红色通道" << endl;
   
    return 0;
}