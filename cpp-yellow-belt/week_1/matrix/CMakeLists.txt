cmake_minimum_required(VERSION 3.5)

project(matrix)

add_executable(matrix main.cpp)
set_target_properties(
        matrix PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(matrix PUBLIC cxx_std_17)
