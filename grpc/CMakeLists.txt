cmake_minimum_required(VERSION 3.16)

project(grpc_demo)

find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

add_executable(server
    server.cpp
    predict.pb.cc
    predict.grpc.pb.cc
)

target_link_libraries(server
    gRPC::grpc++
    protobuf::libprotobuf
)

add_executable(client
    client.cpp
    predict.pb.cc
    predict.grpc.pb.cc
)

target_link_libraries(client
    gRPC::grpc++
    protobuf::libprotobuf
)