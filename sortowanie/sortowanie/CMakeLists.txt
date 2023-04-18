cmake_minimum_required(VERSION 3.24)
project(sortowanie)

set(CMAKE_CXX_STANDARD 17)

add_executable(sortowanie src/main.cpp inc/Sortowanie_przez_scalanie.h inc/Quicksort.h inc/Sortowanie_kubelkowe.h)
