cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 17)
project(Lane_Lines_Detector)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")

find_package(OpenCV 4.5 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

# Find all executables
file(GLOB project_SRCS src/*.cpp src/*.h)
#src/main.cpp src/file_handle.cpp src/camera_calibration.cpp src/file_handle.h src/camera_calibration.h
# Add project executable
add_executable(laneline_detector ${project_SRCS})
target_link_libraries(laneline_detector ${OpenCV_LIBRARIES})