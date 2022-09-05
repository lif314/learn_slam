cmake_minimum_required(VERSION 2.8)

project(helloSLAM)

add_executable(helloSLAM main.cpp)

add_library(libHello libHello.cpp)

add_executable(useHello useHello.cpp)

target_link_libraries(useHello libHello)
