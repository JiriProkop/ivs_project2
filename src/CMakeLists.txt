cmake_minimum_required(VERSION 3.14)
project(calc)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(googletest)
include_directories(googletest/include)

add_executable(calc_tests calc_tests.cpp)
target_link_libraries(calc_tests gtest_main)

add_library(calc_functions calc_funcs.cpp)
target_link_libraries(calc_tests calc_functions)