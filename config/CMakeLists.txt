cmake_minimum_required(VERSION 3.20)

project(config_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(nlohmann_json REQUIRED)

add_executable(config_demo
    main.cpp
    config.cpp
)
