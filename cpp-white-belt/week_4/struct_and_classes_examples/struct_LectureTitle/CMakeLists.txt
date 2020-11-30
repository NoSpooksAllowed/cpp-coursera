cmake_minimum_required(VERSION 3.5)

project(struct_LectureTitle)

add_executable(struct_LectureTitle main.cpp)
set_target_properties(
        struct_LectureTitle PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)
