cmake_minimum_required(VERSION 3.5)

project(set_of_figures)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
        circle.cpp
        rect.cpp
        triangle.cpp        
        create_figure.cpp
)

set(HEADERS
    circle.h
    rect.h
    triangle.h
    i_figure.h
    create_figure.h    
)

add_executable(set_of_figures ${SOURCES} ${HEADERS})
set_target_properties(
        set_of_figures PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(set_of_figures PUBLIC cxx_std_17)
