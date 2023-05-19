cmake_minimum_required(VERSION 3.23)
project(struktury_danych)

set(CMAKE_CXX_STANDARD 23)

add_executable(struktury_danych source/main.cpp
        source/graph_adjacent_list.cpp source/graph_adjacent_list.h
        source/vector.cpp source/vector.h
        source/graph_vector_adjacent.cpp source/graph_vector_adjacent.h
        source/graph_two_dim_array.cpp source/graph_two_dim_array.h
        source/pair.cpp source/pair.h)
