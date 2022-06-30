cmake_minimum_required(VERSION 3.22)
project(Navigation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Navigation
        graphicsStuff.cpp
        main.cpp
        Navigation.cpp
        Navigation.h
        NavigationInterface.h)
