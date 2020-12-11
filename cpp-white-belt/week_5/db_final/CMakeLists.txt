cmake_minimum_required(VERSION 3.5)

project(db_final)

add_executable(db_final main.cpp)
set_target_properties(
        db_final PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(db_final PUBLIC cxx_std_17)
