cmake_minimum_required(VERSION 3.24)
project(tapl CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

add_subdirectory(tapl)
add_subdirectory(bin)

enable_testing()
add_subdirectory(tests)