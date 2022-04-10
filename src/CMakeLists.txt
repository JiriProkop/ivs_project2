cmake_minimum_required(VERSION 3.12) # version can be different

project(calc) #name of project

add_subdirectory(googletest) # googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(calc_tests calc_tests.cpp)

target_link_libraries(calc_tests PRIVATE gtest) # link google test to this executable