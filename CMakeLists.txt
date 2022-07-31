cmake_minimum_required(VERSION 2.8)
project(kmeans)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

set(SOURCE_FILES src/kmeans.cpp src/points.cpp)

add_library(kmeans_lib ${SOURCE_FILES})

add_executable(kmeans_test test.cpp)
target_link_libraries(kmeans_test kmeans_lib)
