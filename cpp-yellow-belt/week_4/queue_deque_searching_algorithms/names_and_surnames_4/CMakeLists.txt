cmake_minimum_required(VERSION 3.5)

project(names_and_surnames_4)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
        person.cpp
)

set(HEADERS
    person.h
)

add_executable(names_and_surnames ${SOURCES} ${HEADERS})
set_target_properties(
        names_and_surnames PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(names_and_surnames PUBLIC cxx_std_17)
