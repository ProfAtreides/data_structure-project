cmake_minimum_required(VERSION 3.23)
project(program)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

set(SOURCES
        source/graph_two_dim_array.cpp source/graph_vector_adjacent.cpp source/graph_adjacent_list.cpp
        source/main.cpp include/graph.h)

add_executable(program ${SOURCES})



