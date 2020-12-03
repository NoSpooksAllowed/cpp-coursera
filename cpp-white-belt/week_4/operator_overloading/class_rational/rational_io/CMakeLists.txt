cmake_minimum_required(VERSION 3.5)

project(rational_io)

add_executable(rational_io main.cpp)
set_target_properties(
        rational_io PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(rational_io PUBLIC cxx_std_17)
