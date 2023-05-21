//
// Created by dambr on 25.04.2023.
//


#include "vector.h"
#include "pair.h"
#include <fstream>



class graph_vector_adjacent {

    //Vector of verticies, each vector has a vector of vertcies(first in pair)
    //adjacent to the vertice with it's node weight
    vector <vector<pair<int,int>>> verticies;

    graph_vector_adjacent(auto source);
    ~graph_vector_adjacent();

    void load_data(auto source); // !add data stream

    int find_max_flow();
    int bfs();
};

