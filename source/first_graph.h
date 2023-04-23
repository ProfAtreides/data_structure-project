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
    int end_vertex,cost;
    bool used;
    node* next_node;
};

struct edge{
    int start_vertex,end_vertex,possible_flow;
};

struct path{
    node* nodes;
    int flow_value,size,end_vertex;
    path();
    path operator+=(node *n);
    node top();
};

class first_graph { // adjacency list refactor code later !
    int nodes_number;
    int end_vertex;
public:
    node** nodes;

    first_graph(edge edges[],int n, int nodes_number);

    ~first_graph();

    void load_data(fstream f);

    void print_data();

    int find_max_flow();

    node* get_node(int end_vertex,int weight,node *nodes);

    int find_path(path &path);
};






#endif //STRUKTURY_DANYCH_FIRST_GRAPH_H
