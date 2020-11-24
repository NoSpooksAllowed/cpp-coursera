cmake_minimum_required(VERSION 3.5)

project(class_string)

add_executable(class_string main.cpp)
set_target_properties(
        class_string PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
