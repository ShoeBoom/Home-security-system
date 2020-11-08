cmake_minimum_required(VERSION 3.16)
project(cs3307)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cs3307 main.cpp)
target_link_libraries(cs3307 ${OpenCV_LIBS})
