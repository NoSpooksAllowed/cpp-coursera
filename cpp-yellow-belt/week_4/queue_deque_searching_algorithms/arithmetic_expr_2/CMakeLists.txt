cmake_minimum_required(VERSION 3.5)

project(arithmetic_expr_2)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
)

set(HEADERS
)

add_executable(arithmetic_expr_2 ${SOURCES} ${HEADERS})
set_target_properties(
        arithmetic_expr_2 PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(arithmetic_expr_2 PUBLIC cxx_std_17)
