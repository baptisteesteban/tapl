cmake_minimum_required(VERSION 3.24)
project(tapl CXX)

set(CMAKE_CXX_STANDARD 20)
option(BUILD_TESTING "Build Tests" ON)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

add_subdirectory(tapl)
add_subdirectory(bin)

if (BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif(BUILD_TESTING)