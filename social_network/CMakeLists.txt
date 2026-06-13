cmake_minimum_required(VERSION 3.15)
project(SocialNetwork VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(soc_net main.cpp user.cpp user.h)