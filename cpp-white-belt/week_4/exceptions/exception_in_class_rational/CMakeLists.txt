cmake_minimum_required(VERSION 3.5)

project(rational_exception)

add_executable(rational_exception main.cpp)
set_target_properties(
        rational_exception PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(rational_exception PUBLIC cxx_std_17)
