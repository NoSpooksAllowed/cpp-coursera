cmake_minimum_required(VERSION 3.5)

project(inverted_function_2)

add_executable(inverted_function_2 main.cpp)
set_target_properties(
        inverted_function_2 PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
