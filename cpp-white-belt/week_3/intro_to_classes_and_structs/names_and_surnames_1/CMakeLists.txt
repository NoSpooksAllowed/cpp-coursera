cmake_minimum_required(VERSION 3.5)

project(names_and_surnames_1)

add_executable(names_and_surnames_1 main.cpp)
set_target_properties(
        names_and_surnames_1 PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
