cmake_minimum_required(VERSION 3.5)

project(synonyms)

add_executable(synonyms main.cpp)
set_target_properties(
        synonyms PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
