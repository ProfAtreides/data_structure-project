//
// Created by dambr on 16.04.2023.
//

#include "first_graph.h"

first_graph::first_graph(edge edges[], int n, int nodes_number) {

    nodes =  new node*[nodes_number]();

    this->nodes_number = nodes_number;

    int temp_end_vertex=0;

    for (int i = 0 ;i < nodes_number;i++) nodes[i] = nullptr;

    for(int  i =0 ;i < n; i++)
    {
        int start_vertex = edges[i].start_vertex;
        int end_vertex = edges[i].end_vertex;
        int used = edges[i].possible_flow;

        if(end_vertex > temp_end_vertex) temp_end_vertex = end_vertex;

        node* temp_node = get_node(end_vertex,used,nodes[start_vertex]);

        nodes[start_vertex] = temp_node;
    }

   end_vertex = temp_end_vertex;
}

void first_graph::load_data(fstream f) {

}

void first_graph::print_data()
{
    for (int i = 0; i < nodes_number; i++)
    {
        while (nodes[i] != nullptr) {
            cout << "(" << i << ", " << nodes[i]->end_vertex
                 << ", " << nodes[i]->cost << ") ";
            nodes[i] = nodes[i]->next_node;
        }
        cout <<"\n";
    }

}

node *first_graph::get_node(int end_vertex, int weight, node *nodes)
{
    node* temp_node = new node;
    temp_node->cost = weight;
    temp_node->end_vertex = end_vertex;
    temp_node->next_node = nodes;

    return temp_node;
}

first_graph::~first_graph() {
    for (int i = 0; i < nodes_number; i++) delete[] nodes[i];

    delete[] nodes;
}

int first_graph::find_path(path &path) { // returns iterator of last vertex in path

    while(path.top().end_vertex == end_vertex  ||
          path.top().used == true) {
        if(path.top().next_node != nullptr) path += path.top().next_node;

    }

    return 0;
}

int first_graph::find_max_flow() {

    int max_flow = 0;

    path path;

    path += nodes[0];
    find_path(path);

    max_flow += find_path(path);

    return 0;
}

path::path(){
    flow_value = 0;
    size = 0;
    end_vertex = 0;
}

path path::operator+=(node *n) {
    path temp;
    temp.nodes = new node[size+1];
    temp.nodes = this->nodes;
    temp.size = this->size+1;
    temp.nodes[size] = *n;
    return temp;
}

node path::top(){
    return nodes[size-1];
}


