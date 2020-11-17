cmake_minimum_required(VERSION 3.5)

project(build_map_values_set)

set(SOURCES
        main.cpp
        build_map_values_set.cpp
)

set(HEADERS
        build_map_values_set.h
)

add_executable(build_map_values_set ${SOURCES} ${HEADERS})
set_target_properties(
        build_map_values_set PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
