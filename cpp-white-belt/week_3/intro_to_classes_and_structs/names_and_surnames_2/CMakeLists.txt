cmake_minimum_required(VERSION 3.5)

project(names_and_surnames_2)

add_executable(names_and_surnames_2 main.cpp)
set_target_properties(
        names_and_surnames_2 PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
