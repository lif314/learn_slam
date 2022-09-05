cmake_minimum_required(VERSION 3.0)

project(VSCODE_DEV)

# 添加编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
# 设置程序调试
set(CMAKE_BUILD_TYPE Debug)

# ${CMAKE_SOURCE_DIR} 当前绝对路径
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(cmake_main.exe main.cpp src/Gun.cpp src/Soldier.cpp)