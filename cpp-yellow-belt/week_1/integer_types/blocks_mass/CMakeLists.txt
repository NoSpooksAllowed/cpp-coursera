cmake_minimum_required(VERSION 3.5)

project(blocks_mass)

add_executable(blocks_mass main.cpp)
set_target_properties(
        blocks_mass PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(blocks_mass PUBLIC cxx_std_17)
