cmake_minimum_required(VERSION 3.13)
project(benchmark)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp benchmark.cpp)

find_package(CGAL)

add_executable(benchmark ${SOURCE_FILES})

target_link_libraries(benchmark CGAL::CGAL)