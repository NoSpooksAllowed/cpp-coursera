cmake_minimum_required(VERSION 3.5)

project(find_greater_elms)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
)

set(HEADERS
        find_greater_elements.h 
)

add_executable(find_greater_elms ${SOURCES} ${HEADERS})
set_target_properties(
        find_greater_elms PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(find_greater_elms PUBLIC cxx_std_17)
