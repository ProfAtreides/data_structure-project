//
// Created by dambr on 25.04.2023.
//

#ifndef STRUKTURY_DANYCH_GRAPH_TWO_DIM_ARRAY_H
#pragma once
#include <fstream>
#include <iostream>
#include "vector.cpp"
#define STRUKTURY_DANYCH_GRAPH_TWO_DIM_ARRAY_H


class graph_two_dim_array {
    int** graph_matrix;
    int size;
public:
    graph_two_dim_array(int size);
    ~graph_two_dim_array();
    void load_data();

    void bfs();
    int find_max_flow(vector <vector<int>> path);
};


#endif //STRUKTURY_DANYCH_GRAPH_TWO_DIM_ARRAY_H
