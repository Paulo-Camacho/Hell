cmake_minimum_required(VERSION 3.28)
project(un)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(un
        main.cpp
        main.h)
