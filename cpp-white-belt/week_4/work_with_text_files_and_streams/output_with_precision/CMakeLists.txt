cmake_minimum_required(VERSION 3.5)

project(output_with_precision)

add_executable(output_with_precision main.cpp)
set_target_properties(
        output_with_precision PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
