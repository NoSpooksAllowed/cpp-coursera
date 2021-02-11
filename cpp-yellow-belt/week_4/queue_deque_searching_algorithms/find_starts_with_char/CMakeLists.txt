cmake_minimum_required(VERSION 3.5)

project(group_by_sym)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
)

set(HEADERS
        find_starts_with.h    
)

add_executable(group_by_sym ${SOURCES} ${HEADERS})
set_target_properties(
        group_by_sym PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(group_by_sym PUBLIC cxx_std_17)
