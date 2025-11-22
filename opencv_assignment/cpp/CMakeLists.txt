cmake_minimum_required(VERSION 3.22)
project(OpenCVTasks)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找OpenCV包
find_package(OpenCV REQUIRED)

# 包含头文件目录
include_directories(${OpenCV_INCLUDE_DIRS})

# 添加可执行文件
add_executable(task2_grayscale task2_grayscale.cpp)

# 链接OpenCV库
target_link_libraries(task2_grayscale ${OpenCV_LIBS})

set_target_properties(task2_grayscale PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/..
)
# 添加TASK3
add_executable(task3_black_bg task3_black_bg.cpp)
target_link_libraries(task3_black_bg ${OpenCV_LIBS})
set_target_properties(task3_black_bg PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/..
)
# 添加TASK4
add_executable(task4_RGB task4_RGB.cpp)
target_link_libraries(task4_RGB ${OpenCV_LIBS})
set_target_properties(task4_RGB PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/..
)
add_executable(task5_text_contours task5_text_contours.cpp)
target_link_libraries(task5_text_contours ${OpenCV_LIBS})
set_target_properties(task5_text_contours PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/..
)
add_executable(task6_rotate task6_rotate.cpp)
target_link_libraries(task6_rotate ${OpenCV_LIBS})
set_target_properties(task6_rotate PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/..
)