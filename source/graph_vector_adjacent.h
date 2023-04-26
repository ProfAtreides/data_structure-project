//
// Created by dambr on 25.04.2023.
//

#ifndef STRUKTURY_DANYCH_GRAPH_VECTOR_ADJACENT_H
#include "vector.h"
#define STRUKTURY_DANYCH_GRAPH_VECTOR_ADJACENT_H


class graph_vector_adjacent {

    struct node{
        int start_vertice,end_vertice,value;
    };

    vector <vector<node>> links;


};


#endif //STRUKTURY_DANYCH_GRAPH_VECTOR_ADJACENT_H
