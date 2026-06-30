cmake_minimum_required(VERSION 3.16)

project(ndlite)

find_package(pybind11 REQUIRED)

pybind11_add_module(ndlite ndlite.h ndlite.cpp)