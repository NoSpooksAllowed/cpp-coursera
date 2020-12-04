cmake_minimum_required(VERSION 3.5)

project(rational_calculator)

add_executable(rational_calculator main.cpp)
set_target_properties(
        rational_calculator PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(rational_calculator PUBLIC cxx_std_17)
