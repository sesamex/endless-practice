#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace cv;

int main() {
    string input_path = "images/IMG_20251118_142320.jpg";
    string output_path = "results/task6_rotated_cpp.jpg";
    
    // 读取图片
    Mat img = imread(input_path);
    if (img.empty()) {
        cout << "错误: 无法读取图片 " << input_path << endl;
        return -1;
    }
    
    int height = img.rows;
    int width = img.cols;
    
    cout << "原始图片尺寸: " << width << " x " << height << endl;
    
    // 获取图片中心点
    Point2f center(static_cast<float>(width) / 2, static_cast<float>(height) / 2);
    cout << "旋转中心: (" << center.x << ", " << center.y << ")" << endl;
    
    // 计算旋转矩阵
    // 参数：中心点，旋转角度，缩放比例
    Mat rotation_matrix = getRotationMatrix2D(center, 45.0, 1.0);
    cout << "旋转矩阵计算完成" << endl;
    
    // 计算旋转后的图片尺寸
    double cos_val = abs(rotation_matrix.at<double>(0, 0));
    double sin_val = abs(rotation_matrix.at<double>(0, 1));
    
    int new_width = static_cast<int>((height * sin_val) + (width * cos_val));
    int new_height = static_cast<int>((height * cos_val) + (width * sin_val));
    
    cout << "新图片尺寸: " << new_width << " x " << new_height << endl;
    
    // 调整旋转矩阵，考虑图片中心移动
    rotation_matrix.at<double>(0, 2) += (new_width / 2.0) - center.x;
    rotation_matrix.at<double>(1, 2) += (new_height / 2.0) - center.y;
    
    // 执行旋转
    Mat rotated_img;
    warpAffine(
        img, 
        rotated_img, 
        rotation_matrix, 
        Size(new_width, new_height),
        INTER_LINEAR,
        BORDER_CONSTANT,
        Scalar(255, 255, 255)  // 白色背景
    );
    
    // 保存结果
    imwrite(output_path, rotated_img);
    
    cout << "TASK6完成(C++版本): 图片旋转45度完成" << endl;
    cout << "结果保存为: " << output_path << endl;
    cout << "原始尺寸: " << width << " x " << height << endl;
    cout << "旋转后尺寸: " << new_width << " x " << new_height << endl;
    
    return 0;
}