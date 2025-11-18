cmake_minimum_required(VERSION 3.22)
project(task7)

set(CMAKE_CXX_STANDARD 11)

add_executable(task7 main.cpp)

target_compile_options(task7 PRIVATE -Wall -Wextra)