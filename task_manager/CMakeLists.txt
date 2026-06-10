cmake_minimum_required(VERSION 3.15)
project(TaskManager VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task_manager main.cpp task_manager.cpp task_manager.h task.h)