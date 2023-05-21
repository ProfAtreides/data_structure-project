//
// Created by dambr on 25.04.2023.
//

#pragma once

#include <string>

class graph_two_dim_array
{
    int** graph_matrix;
    int size;

    public:
    graph_two_dim_array();
    graph_two_dim_array(std::string data,int size);
    ~graph_two_dim_array();
    bool bfs(int **resudal_matrix,int path[]);
    int find_max_flow();
};

