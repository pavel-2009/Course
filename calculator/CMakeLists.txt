cmake_minimum_required(VERSION 3.15)

project(Calculator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(calc main.cpp calculator.cpp calculator.h)