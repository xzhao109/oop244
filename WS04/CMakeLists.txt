cmake_minimum_required(VERSION 3.22)
project(WS04)

set(CMAKE_CXX_STANDARD 14)

include_directories(lab)

add_executable(WS04
        lab/Car.cpp
        lab/Car.h
        lab/main.cpp)
