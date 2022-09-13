cmake_minimum_required(VERSION 3.0)

find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})
add_executable(plotTrajectory 3-plotTrajectory.cpp)
target_link_libraries(plotTrajectory ${Pangolin_LIBRARIES})