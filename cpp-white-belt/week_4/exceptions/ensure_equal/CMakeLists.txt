cmake_minimum_required(VERSION 3.5)

project(ensure_equal)

add_executable(ensure_equal main.cpp)
set_target_properties(
        ensure_equal PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(ensure_equal PUBLIC cxx_std_17)
