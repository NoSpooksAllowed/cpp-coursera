cmake_minimum_required(VERSION 3.5)

project(student_list)

add_executable(student_list main.cpp)
set_target_properties(
        student_list PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
