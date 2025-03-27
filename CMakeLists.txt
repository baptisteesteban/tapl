cmake_minimum_required(VERSION 3.24)
project(tapl CXX)

add_subdirectory(tapl)
add_subdirectory(bin)

enable_testing()
add_subdirectory(tests)