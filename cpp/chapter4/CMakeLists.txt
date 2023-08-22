cmake_minimum_required(VERSION 2.8.12)
PROJECT(chapter4_opencv)

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(CMAKE_CXX_STANDARD 11)

SET(OPENCV_CONFIG_PATH "/home/pupil/install/opencv/opencv_install/lib/cmake/opencv4")
list(APPEND CMAKE_PREFIX_PATH ${OPENCV_CONFIG_PATH})

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

MACRO(add_example name)
  ADD_EXECUTABLE(${name} ${name}.cpp)
  TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS})
ENDMACRO()

add_example(uchar_image)
add_example(integral_images)
