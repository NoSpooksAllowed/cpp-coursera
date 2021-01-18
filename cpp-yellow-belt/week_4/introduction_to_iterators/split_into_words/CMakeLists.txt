cmake_minimum_required(VERSION 3.5)

project(split_into_words)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
        split_into_words.cpp
)

set(HEADERS
        split_into_words.h    
)

add_executable(split_into_words ${SOURCES} ${HEADERS})
set_target_properties(
        split_into_words PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(split_into_words PUBLIC cxx_std_17)
