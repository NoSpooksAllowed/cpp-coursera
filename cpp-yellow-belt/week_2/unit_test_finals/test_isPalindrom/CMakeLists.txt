cmake_minimum_required(VERSION 3.5)

project(test_IsPalindrom)

set(CMAKE_BUILD_TYPE Debug)

add_executable(test_IsPalindrom main.cpp)
set_target_properties(
        test_IsPalindrom PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(test_IsPalindrom PUBLIC cxx_std_17)
