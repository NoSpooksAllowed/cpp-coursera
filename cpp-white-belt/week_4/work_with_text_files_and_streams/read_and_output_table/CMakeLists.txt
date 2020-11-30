cmake_minimum_required(VERSION 3.5)

project(read_and_output_table)

add_executable(read_and_output_table main.cpp)
set_target_properties(
        read_and_output_table PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
