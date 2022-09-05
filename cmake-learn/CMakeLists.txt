# 指定最小版本
cmake_minimum_required(VERSION 3.0)

# 工程名
project(SWAP)

# 头文件目录
include_directories(include)

# 执行文件
add_executable(main_cmake main.cpp src/swap.cpp)