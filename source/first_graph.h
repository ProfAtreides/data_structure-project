//
// Created by dambr on 16.04.2023.
//

#pragma once
#include <fstream>
#include <iostream>
#ifndef STRUKTURY_DANYCH_FIRST_GRAPH_H
#define STRUKTURY_DANYCH_FIRST_GRAPH_H

using namespace std;

struct node{
    int value,cost;
    node* next_node;
};

struct edge{
    int start_vertex,end_vertex,weight;
};

class first_graph { // adjacency list refactor code later !


    int nodes_number;

public:
    node** nodes;
    first_graph(edge edges[],int n, int nodes_number);

    ~first_graph();

    void load_data(fstream f);

    void print_data();

    void find_max_flow();

    node* get_node(int end_vertex,int weight,node *nodes);
};






#endif //STRUKTURY_DANYCH_FIRST_GRAPH_H
