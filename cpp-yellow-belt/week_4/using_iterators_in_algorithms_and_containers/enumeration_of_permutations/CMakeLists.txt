cmake_minimum_required(VERSION 3.5)

project(enumeration_of_permutation)

set(CMAKE_BUILD_TYPE Debug)

add_executable(enumeration_of_permutation main.cpp)
set_target_properties(
        enumeration_of_permutation PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(enumeration_of_permutation PUBLIC cxx_std_17)
