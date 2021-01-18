cmake_minimum_required(VERSION 3.5)

project(vector_part)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
        vector_part.cpp
)

set(HEADERS
        vector_part.h    
)

add_executable(vector_part ${SOURCES} ${HEADERS})
set_target_properties(
        vector_part PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(vector_part PUBLIC cxx_std_17)
