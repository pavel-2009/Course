cmake_minimum_required(VERSION 3.15)
project(MatrixLibrary VERSION 1.0 LANGUAGES CXX)

# Устанавливаем стандарт C++17 или выше
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Говорим компилятору собрать исполняемый файл из трех исходников
add_executable(matrix_app 
    main.cpp 
    matrix.cpp 
    matrix.h
)