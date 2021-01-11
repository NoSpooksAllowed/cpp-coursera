cmake_minimum_required(VERSION 3.5)

project(test_names_and_surnames)

set(CMAKE_BUILD_TYPE Debug)

add_executable(test_names_and_surnames main.cpp)
set_target_properties(
        test_names_and_surnames PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(test_names_and_surnames PUBLIC cxx_std_17)
