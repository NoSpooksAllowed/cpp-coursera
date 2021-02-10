cmake_minimum_required(VERSION 3.5)

project(find_nearest_element)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
        find_nearest_element.cpp
)

set(HEADERS
        find_nearest_element.cpp    
)

add_executable(find_nearest_element ${SOURCES} ${HEADERS})
set_target_properties(
        find_nearest_element PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(find_nearest_element PUBLIC cxx_std_17)
