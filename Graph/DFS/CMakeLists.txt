cmake_minimum_required(VERSION 3.17)
project(DFS)

set(CMAKE_CXX_STANDARD 14)

add_executable(DFS main.cpp AdjacencyList.cpp AdjacencyList.h DFS.cpp DFS.h)