cmake_minimum_required(VERSION 3.5)

project(find_starts_with_char)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
)

set(HEADERS
        find_starts_with.h    
)

add_executable(find_starts_with_char ${SOURCES} ${HEADERS})
set_target_properties(
        find_starts_with_char PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(find_starts_with_char PUBLIC cxx_std_17)
