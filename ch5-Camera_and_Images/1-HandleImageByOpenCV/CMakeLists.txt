cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_FLAGS "--std=c++11")

# OpenCV库
find_package(OpenCV REQUIRED)

# 添加头文件
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(imageBasics imageBasics.cpp)

# 连接OpenCV库
target_link_libraries( imageBasics ${OpenCV_LIBS} )