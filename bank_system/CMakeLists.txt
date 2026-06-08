cmake_minimum_required(VERSION 3.15)

project(BankSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bank main.cpp bank_account.cpp user.cpp transaction.cpp bank_account.h user.h transaction.h)