cmake_minimum_required(VERSION 3.8)
project(cli_novel)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Graph.cpp src/headers/Graph.h src/Game.cpp src/headers/Game.h)
add_executable(cli_novel ${SOURCE_FILES})