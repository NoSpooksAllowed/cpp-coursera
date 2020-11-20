cmake_minimum_required(VERSION 3.5)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(sorted_strings)

add_executable(sorted_strings main.cpp)
set_target_properties(
        sorted_strings PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
