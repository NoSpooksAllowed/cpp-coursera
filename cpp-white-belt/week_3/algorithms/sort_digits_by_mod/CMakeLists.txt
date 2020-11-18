cmake_minimum_required(VERSION 3.5)

project(sort_digits_by_mod)

add_executable(sort_digits_by_mod main.cpp)
set_target_properties(
        sort_digits_by_mod PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
