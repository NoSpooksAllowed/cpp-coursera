cmake_minimum_required(VERSION 3.5)

project(rational_interface)

add_executable(rational_interface main.cpp)
set_target_properties(
        rational_interface PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
