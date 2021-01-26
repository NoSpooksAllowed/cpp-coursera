cmake_minimum_required(VERSION 3.5)

project(merge_sort)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
)

set(HEADERS
        merge_sort.h    
)

add_executable(merge_sort ${SOURCES} ${HEADERS})
set_target_properties(
        merge_sort PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(merge_sort PUBLIC cxx_std_17)
