cmake_minimum_required(VERSION 3.5)

project(rational_eq_add_sub)

add_executable(rational_eq_add_sub main.cpp)
set_target_properties(
        rational_eq_add_sub PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(rational_eq_add_sub PUBLIC cxx_std_17)
