cmake_minimum_required(VERSION 3.10)
project(TrashGuy_cpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(TrashGuy_cpp main.cpp)
target_include_directories(TrashGuy_cpp PRIVATE ./include/)
