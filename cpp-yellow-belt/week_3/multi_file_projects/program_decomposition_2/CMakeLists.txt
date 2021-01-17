cmake_minimum_required(VERSION 3.5)

project(bus_manager)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
        query.cpp
        responses.cpp
        bus_manager.cpp
)

set(HEADERS
    query.h
    responses.h
    bus_manager.h
)

add_executable(bus_manager ${SOURCES} ${HEADERS})
set_target_properties(
        bus_manager PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(bus_manager PUBLIC cxx_std_17)
