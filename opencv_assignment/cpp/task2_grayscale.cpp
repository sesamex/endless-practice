#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>  // 使用fstream导入资源管理器
#include <sys/stat.h>  // 用于检查文件是否存在

using namespace std;
using namespace cv;

bool file_exists(const string& path) {
    // 传统方法检查文件是否存在
    ifstream file(path);
    return file.good();
}

string find_image_path() {
    vector<string> possible_paths = {
        "images/IMG_20251118_142320.jpg",
        "../images/IMG_20251118_142320.jpg", 
        "../../images/IMG_20251118_142320.jpg"
    };
    
    for (const auto& path : possible_paths) {
        if (file_exists(path)) {
            cout << "找到图片路径: " << path << endl;
            return path;
        }
    }
    return "";
}

int main() {
    string input_path = find_image_path();
    if (input_path.empty()) {
        cout << "错误: 找不到图片文件" << endl;
        system("pwd");
        return -1;
    }
    
    string output_path = "results/task2_gray_cpp.jpg";
    
    Mat original_image = imread(input_path);
    if (original_image.empty()) {
        cout << "错误: 无法读取图片 " << input_path << endl;
        return -1;
    }
    
    Mat grayscale_image;
    cvtColor(original_image, grayscale_image, COLOR_BGR2GRAY);
    
    bool success = imwrite(output_path, grayscale_image);
    if (!success) {
        cout << "错误: 无法保存图片 " << output_path << endl;
        return -1;
    }
    
    cout << "TASK2完成: 灰度图已保存为 " << output_path << endl;
    cout << "图片尺寸: " << original_image.cols << " x " << original_image.rows << endl;
    
    return 0;
}