cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(checkers  inc/table.h src/main.cpp inc/piece.h src/table.cpp src/piece.cpp)
