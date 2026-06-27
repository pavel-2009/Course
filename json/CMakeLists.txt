cmake_minimum_required(VERSION 3.20)

project(JsonDemo)

set(CMAKE_CXX_STANDARD 20)

find_package(nlohmann_json REQUIRED)

add_executable(app main.cpp)

target_link_libraries(
    app
    PRIVATE
    nlohmann_json::nlohmann_json
)