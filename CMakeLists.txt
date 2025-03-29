cmake_minimum_required(VERSION 3.24)
project(tapl CXX)

option(BUILD_TESTING "Build Tests" ON)

include(GNUInstallDirs)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

add_subdirectory(tapl)
add_subdirectory(bin)

if (BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif(BUILD_TESTING)