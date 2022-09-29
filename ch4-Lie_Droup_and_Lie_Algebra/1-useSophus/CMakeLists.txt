find_package(Sophus REQUIRED)

include_directories($Sophus_INCLUDE_DIRS)

add_executable(useSophus 1-useSophus.cpp)
target_link_libraries( useSophus Sophus::Sophus )
