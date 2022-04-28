cmake_minimum_required(VERSION 3.5)
project(main)
include_directories(AFTER /home/sjbhyf/Classes/3220/Project/ECE3220Project)
set(INCLUDE_FILES
    /Dialogue/dialogue.hpp
    /
add_executable(main main.cpp)
target_link_libraries(main PUBLIC)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)