cmake_minimum_required(VERSION 3.5)

project(final)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
        date.cpp
        database.cpp
        node.cpp
        token.cpp
        condition_parser.cpp
        condition_parser_test.cpp
)

set(HEADERS
    helpers.h
    date.h
    database.h
    test_runner.h
    node.h
    token.h
    condition_parser.h
    test_db.h
)

add_executable(main ${SOURCES} ${HEADERS})
set_target_properties(
        main PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(main PUBLIC cxx_std_17)
