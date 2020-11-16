cmake_minimum_required(VERSION 3.5)

project(capitals_handbook)

add_executable(countries main.cpp)
set_target_properties(
        countries PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
