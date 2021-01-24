cmake_minimum_required(VERSION 3.5)

project(demographic_data)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
        print_stats.cpp
)

set(HEADERS
        print_stats.h    
        compute_median_age.h
        person.h
)

add_executable(demographic_data ${SOURCES} ${HEADERS})
set_target_properties(
        demographic_data PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(demographic_data PUBLIC cxx_std_17)
