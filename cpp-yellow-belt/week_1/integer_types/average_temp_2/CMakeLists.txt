cmake_minimum_required(VERSION 3.5)

project(average_temp_2)

add_executable(average_temp_2 main.cpp)
set_target_properties(
        average_temp_2 PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(average_temp_2 PUBLIC cxx_std_17)
