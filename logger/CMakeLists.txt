cmake_minimum_required(VERSION 3.22)

project(Logger LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    Logger
    main.cpp
    src/logger.cpp
)

target_include_directories(Logger PRIVATE include)