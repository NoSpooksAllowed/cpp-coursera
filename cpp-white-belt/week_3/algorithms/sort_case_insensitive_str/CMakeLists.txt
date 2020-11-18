cmake_minimum_required(VERSION 3.5)

project(sort_case_insensitive_str)

add_executable(sort_case_insensitive_str main.cpp)
set_target_properties(
        sort_case_insensitive_str PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
