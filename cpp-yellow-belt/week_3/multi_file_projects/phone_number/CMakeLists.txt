cmake_minimum_required(VERSION 3.5)

project(phone_number)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
        phone_number.cpp
)

set(HEADERS
        phone_number.h    
)

add_executable(phone_number ${SOURCES} ${HEADERS})
set_target_properties(
        phone_number PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(phone_number PUBLIC cxx_std_17)
