#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main() {
    /**
     * TASK5: 将图片的文字部分用红色轮廓圈出
     * 流程: 灰度图 -> 二值化 -> 膨胀 -> 描边
     */
    
    string input_path = "images/IMG_20251118_142320.jpg";
    string output_path = "results/task5_contours_cpp.jpg";
    
    // 读取图片
    Mat img = imread(input_path);
    if (img.empty()) {
        cout << "错误: 无法读取图片 " << input_path << endl;
        return -1;
    }
    
    cout << "原始图片尺寸: " << img.cols << " x " << img.rows << endl;
    
    // 步骤1: 转换为灰度图
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    cout << "步骤1: 灰度图转换完成" << endl;
    
    // 步骤2: 高斯模糊，减少噪点
    Mat blurred;
    GaussianBlur(gray, blurred, Size(5, 5), 0);
    
    // 步骤3: 二值化
    Mat binary;
    adaptiveThreshold(blurred, binary, 255, ADAPTIVE_THRESH_GAUSSIAN_C, 
                     THRESH_BINARY_INV, 15, 5);
    cout << "步骤2: 二值化完成" << endl;
    
    // 步骤4: 形态学操作 - 开运算去除小噪点
    Mat kernel1 = getStructuringElement(MORPH_RECT, Size(2, 2));
    Mat cleaned;
    morphologyEx(binary, cleaned, MORPH_OPEN, kernel1);
    
    // 步骤5: 膨胀操作连接文字
    Mat kernel2 = getStructuringElement(MORPH_RECT, Size(3, 3));
    Mat dilated;
    dilate(cleaned, dilated, kernel2, Point(-1, -1), 2);
    cout << "步骤3: 膨胀操作完成" << endl;
    
    // 步骤6: 查找轮廓
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(dilated, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    cout << "步骤4: 找到 " << contours.size() << " 个轮廓" << endl;
    
    // 步骤7: 过滤小轮廓
    vector<vector<Point>> filtered_contours;
    double min_area = 100.0;
    
    for (const auto& contour : contours) {
        double area = contourArea(contour);
        if (area > min_area) {
            filtered_contours.push_back(contour);
        }
    }
    
    cout << "过滤后剩 " << filtered_contours.size() << " 个轮廓" << endl;
    
    // 步骤8: 在原图上用红色绘制轮廓
    Mat result = img.clone();
    Scalar red_color(0, 0, 255);  // BGR: 红色
    drawContours(result, filtered_contours, -1, red_color, 2);
    
    // 保存结果
    imwrite(output_path, result);
    
    cout << "TASK5完成(C++版本): 红色轮廓检测完成" << endl;
    cout << "主要结果: " << output_path << endl;
    cout << "中间步骤已保存用于调试" << endl;
    cout << "过滤掉了 " << contours.size() - filtered_contours.size() << " 个小噪点" << endl;
    
    return 0;
}