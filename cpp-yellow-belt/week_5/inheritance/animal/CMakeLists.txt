cmake_minimum_required(VERSION 3.5)

project(animal)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
        animal.cpp
)

set(HEADERS
        animal.h    
)

add_executable(animal ${SOURCES} ${HEADERS})
set_target_properties(
        animal PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(animal PUBLIC cxx_std_17)
