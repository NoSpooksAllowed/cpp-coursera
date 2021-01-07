cmake_minimum_required(VERSION 3.5)

project(program_decomposition)

set(CMAKE_BUILD_TYPE Debug)

add_executable(program_decomposition main.cpp)
set_target_properties(
        program_decomposition PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(program_decomposition PUBLIC cxx_std_17)
