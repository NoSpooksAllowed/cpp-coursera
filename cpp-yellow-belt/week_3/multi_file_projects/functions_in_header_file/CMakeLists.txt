cmake_minimum_required(VERSION 3.5)

project(sum_reverse_sort)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
        sum_reverse_sort.cpp
)

set(HEADERS
        sum_reverse_sort.h    
)

add_executable(sum_reverse_sort ${SOURCES} ${HEADERS})
set_target_properties(
        sum_reverse_sort PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(sum_reverse_sort PUBLIC cxx_std_17)
