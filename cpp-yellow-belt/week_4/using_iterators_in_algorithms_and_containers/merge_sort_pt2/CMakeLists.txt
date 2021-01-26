cmake_minimum_required(VERSION 3.5)

project(merge_sort_2)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
)

set(HEADERS
        merge_sort.h    
)

add_executable(merge_sort_2 ${SOURCES} ${HEADERS})
set_target_properties(
        merge_sort_2 PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(merge_sort_2 PUBLIC cxx_std_17)
