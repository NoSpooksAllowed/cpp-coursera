cmake_minimum_required(VERSION 3.5)

project(tasks_tracker)

set(CMAKE_BUILD_TYPE Debug)

add_executable(tasks_tracker main.cpp)
set_target_properties(
        tasks_tracker PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(tasks_tracker PUBLIC cxx_std_17)
