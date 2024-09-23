cmake_minimum_required(VERSION 3.10)

project(FaceTracking)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.cpp serialib.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})