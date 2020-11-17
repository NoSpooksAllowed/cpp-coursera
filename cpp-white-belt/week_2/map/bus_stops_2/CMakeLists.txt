cmake_minimum_required(VERSION 3.5)

project(bus_stops_2)

add_executable(bus_stops main.cpp)
set_target_properties(
        bus_stops PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
