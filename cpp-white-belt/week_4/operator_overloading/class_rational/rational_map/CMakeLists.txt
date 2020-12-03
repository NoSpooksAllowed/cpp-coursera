cmake_minimum_required(VERSION 3.5)

project(rational_map)

add_executable(rational_map main.cpp)
set_target_properties(
        rational_map PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(rational_map PUBLIC cxx_std_17)
