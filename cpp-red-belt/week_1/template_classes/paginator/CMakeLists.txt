cmake_minimum_required(VERSION 3.5)

project(paginator)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
)

set(HEADERS
)

add_executable(main ${SOURCES} ${HEADERS})
set_target_properties(
        main PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(main PUBLIC cxx_std_17)
