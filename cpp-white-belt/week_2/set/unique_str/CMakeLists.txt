cmake_minimum_required(VERSION 3.5)

project(unique_str)

add_executable(unique_str main.cpp)
set_target_properties(
        unique_str PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
