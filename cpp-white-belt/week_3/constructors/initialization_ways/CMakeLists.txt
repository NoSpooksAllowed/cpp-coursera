cmake_minimum_required(VERSION 3.5)

project(initialization_ways)

add_executable(initialization_ways main.cpp)
set_target_properties(
        initialization_ways PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
