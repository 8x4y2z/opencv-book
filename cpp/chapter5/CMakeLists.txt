cmake_minimum_required(VERSION 2.8.12)
PROJECT(chapter5_opencv)

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

add_example(1_many_functions)
add_example(2_draw_rect)
add_example(3_draw_rectangle)
add_example(4_roi_pyr)
