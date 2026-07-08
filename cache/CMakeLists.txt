cmake_minimum_required(VERSION 3.20)

project(cache LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cache
    main.cpp
    include/cache.hpp
)

target_include_directories(cache PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
