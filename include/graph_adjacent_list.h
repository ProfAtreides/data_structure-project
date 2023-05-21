//
// Created by dambr on 16.04.2023.
//

#pragma once
#include "vector.h"
#include <fstream>


using namespace std;

struct node{
    int end_vertex,cost;
    node* next_node;
};

struct edge{
    int start_vertex,end_vertex,possible_flow;
};


class graph_adjacent_list { // adjacency list refactor code later !
    int nodes_number;
    int vertice_number;
    // int max_flow;
public:
    node** nodes_in_graph;

    graph_adjacent_list(edge edges[], int n, int nodes_number);

    ~graph_adjacent_list();

    void load_data(fstream f);

    void print_data();

    int find_max_flow(vector <node> path);

    int ford();

    node* get_node(int end_vertex,int weight,node *nodes);

    void find_paths();
};






