# Minimal version of cmake
cmake_minimum_required(VERSION 3.20)

# Project name
project(ShapeDetection)

# Get all required package of opencv
find_package(OpenCV REQUIRED)

# Set the output directory for executable file
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")

# Include libs and source files directories
include_directories(/usr/local/include/opencv4/)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

# Executable file
add_executable(ShapeDetection ${SOURCES})

# Link opencv libraries
target_link_directories(ShapeDetection PUBLIC /usr/local/include/opencv4/)
