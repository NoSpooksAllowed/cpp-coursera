cmake_minimum_required(VERSION 3.5)

project(ref_on_element)

set(CMAKE_BUILD_TYPE Debug)

add_executable(ref_on_element main.cpp)
set_target_properties(
        ref_on_element PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(ref_on_element PUBLIC cxx_std_17)
