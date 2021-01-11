cmake_minimum_required(VERSION 3.5)

project(test_Rational)

set(CMAKE_BUILD_TYPE Debug)

add_executable(test_Rational main.cpp)
set_target_properties(
        test_Rational PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(test_Rational PUBLIC cxx_std_17)
