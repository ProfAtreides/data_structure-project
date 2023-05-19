//
// Created by dambr on 25.04.2023.
//

#ifndef STRUKTURY_DANYCH_GRAPH_VECTOR_ADJACENT_H
#include "vector.h"
#include "pair.h"
#include <fstream>
#define STRUKTURY_DANYCH_GRAPH_VECTOR_ADJACENT_H


class graph_vector_adjacent {

    //Vector of verticies, each vector has a vector of vertcies(first in pair)
    //adjacent to the vertice with it's node weight
    vector <vector<pair<int,int>>> verticies;

    graph_vector_adjacent();
    ~graph_vector_adjacent();

    void load_data(); // !add data stream

    int find_max_flow();
    int bfs();
};


#endif //STRUKTURY_DANYCH_GRAPH_VECTOR_ADJACENT_H
