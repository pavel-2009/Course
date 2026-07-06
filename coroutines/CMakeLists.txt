cmake_minimum_required(VERSION 3.20)

project(coroutines)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS system)

add_executable(coroutines main.cpp)

target_link_libraries(coroutines PRIVATE Boost::system pthread)