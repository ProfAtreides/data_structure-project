//
// Created by dambr on 25.04.2023.
//
#pragma once
#ifndef STRUKTURY_DANYCH_GRAPH_TWO_DIM_ARRAY_H
#define STRUKTURY_DANYCH_GRAPH_TWO_DIM_ARRAY_H


class graph_two_dim_array {
    int** graph_matrix;
    int size;
public:
    graph_two_dim_array(int size,int **graph_array);
    ~graph_two_dim_array();
    bool bfs(int **resudal_matrix,int path[]);
    int find_max_flow();
};


#endif //STRUKTURY_DANYCH_GRAPH_TWO_DIM_ARRAY_H
