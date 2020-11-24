cmake_minimum_required(VERSION 3.5)

project(names_and_surnames_3)

add_executable(names_and_surnames_3 main.cpp)
set_target_properties(
        names_and_surnames_3 PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
