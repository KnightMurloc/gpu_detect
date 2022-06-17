cmake_minimum_required(VERSION 3.16)
project(gpu_detect)

set(CMAKE_CXX_STANDARD 17)
find_package(Vulkan REQUIRED FATAL_ERROR)

add_library(${PROJECT_NAME} STATIC gpu_detect.cpp gpu_detect.h)
target_include_directories(${PROJECT_NAME} PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)