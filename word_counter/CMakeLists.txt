cmake_minimum_required(VERSION 3.15)
project(WordCounter VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(word_counter main.cpp word_analyzer.cpp word_analyzer.h text_sanitizer.h text_sanitizer.cpp)