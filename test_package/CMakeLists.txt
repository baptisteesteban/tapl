cmake_minimum_required(VERSION 3.24)
project(TaplTestPackage)

find_package(tapl REQUIRED)

add_executable(test_tapl_simple test_tapl_simple.cpp)
target_link_libraries(test_tapl_simple PRIVATE tapl::simple)