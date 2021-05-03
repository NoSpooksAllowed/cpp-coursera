cmake_minimum_required(VERSION 3.5)

project(sort_students)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

set(SOURCES
        sort_students.cpp
)

set(HEADERS
        test_runner.h    
        student.h
        profile.h
)

add_executable(main ${SOURCES} ${HEADERS})
set_target_properties(
        main PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(main PUBLIC cxx_std_17)
