cmake_minimum_required(VERSION 3.5)

project(time_server)

add_executable(time_server main.cpp)
set_target_properties(
        time_server PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(time_server PUBLIC cxx_std_17)
