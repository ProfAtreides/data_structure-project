//
// Created by dambr on 16.04.2023.
//

#include "first_graph.h"

first_graph::first_graph(edge edges[], int n, int nodes_number) {

    nodes =  new node*[nodes_number]();

    this->nodes_number = nodes_number;

    for (int i = 0 ;i < nodes_number;i++) nodes[i] = nullptr;

    for(int  i =0 ;i < n; i++)
    {
        int start_vertex = edges[i].start_vertex;
        int end_vertex = edges[i].end_vertex;
        int weight = edges[i].weight;

        node* temp_node = get_node(end_vertex,weight,nodes[start_vertex]);

        nodes[start_vertex] = temp_node;
    }
}

void first_graph::find_max_flow() {

}

void first_graph::load_data(fstream f) {

}

void first_graph::print_data()
{
    for (int i = 0; i < nodes_number; i++)
    {
        while (nodes[i] != nullptr) {
            cout << "(" << i << ", " << nodes[i]->value
                 << ", " << nodes[i]->cost << ") ";
            nodes[i] = nodes[i]->next_node;
        }
        cout << endl;
    }


}

node *first_graph::get_node(int end_vertex, int weight, node *nodes)
{
    node* temp_node = new node;
    temp_node->cost = weight;
    temp_node->value = end_vertex;
    temp_node->next_node = nodes;

    return temp_node;
}

first_graph::~first_graph() {
    for (int i = 0; i < nodes_number; i++) delete[] nodes[i];

    delete[] nodes;
}



