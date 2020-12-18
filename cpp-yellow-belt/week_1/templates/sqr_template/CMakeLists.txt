cmake_minimum_required(VERSION 3.5)

project(sqr_template)

set(CMAKE_BUILD_TYPE Debug)

add_executable(sqr_template main.cpp)
set_target_properties(
        sqr_template PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(sqr_template PUBLIC cxx_std_17)
