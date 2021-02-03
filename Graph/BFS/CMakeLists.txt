cmake_minimum_required(VERSION 3.17)
project(BFS)

set(CMAKE_CXX_STANDARD 14)

add_executable(BFS main.cpp AdjacencyList.h AdjacencyList.cpp BFS.cpp BFS.h)