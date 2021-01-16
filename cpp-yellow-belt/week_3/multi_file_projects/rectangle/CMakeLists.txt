cmake_minimum_required(VERSION 3.5)

project(rectangle)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
        rectangle.cpp
)

set(HEADERS
        rectangle.h    
)

add_executable(rectangle ${SOURCES} ${HEADERS})
set_target_properties(
        rectangle PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(rectangle PUBLIC cxx_std_17)
