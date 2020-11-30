cmake_minimum_required(VERSION 3.5)

project(work_with_files)

add_executable(work_with_files main.cpp)
set_target_properties(
        work_with_files PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
