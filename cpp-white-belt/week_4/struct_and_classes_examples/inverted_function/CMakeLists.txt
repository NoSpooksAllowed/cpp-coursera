cmake_minimum_required(VERSION 3.5)

project(inverted_function)

add_executable(inverted_function main.cpp)
set_target_properties(
        inverted_function PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
