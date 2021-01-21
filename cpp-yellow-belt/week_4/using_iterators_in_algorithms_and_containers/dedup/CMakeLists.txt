cmake_minimum_required(VERSION 3.5)

project(dedup)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
)

set(HEADERS
        remove_duplicates.h    
)

add_executable(dedup ${SOURCES} ${HEADERS})
set_target_properties(
        dedup PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(dedup PUBLIC cxx_std_17)
