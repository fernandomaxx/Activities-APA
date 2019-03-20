cmake_minimum_required(VERSION 3.13)
project(GraphAlgorithms_)

set(CMAKE_CXX_STANDARD 14)

add_executable(GraphAlgorithms_ kruskal.cpp graph_adjacency_list.cpp graph_adjacency_list.h graph_adjacency_matrix.cpp graph_adjacency_matrix.h prim.cpp dijkstra.cpp)