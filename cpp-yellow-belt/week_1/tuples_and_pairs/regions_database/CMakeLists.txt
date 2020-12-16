cmake_minimum_required(VERSION 3.5)

project(regions_database)

set(CMAKE_BUILD_TYPE Debug)

add_executable(regions_database main.cpp)
set_target_properties(
        regions_database PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(regions_database PUBLIC cxx_std_17)
