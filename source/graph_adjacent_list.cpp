//
// Created by dambr on 16.04.2023.
//

#include "graph_adjacent_list.h"

graph_adjacent_list::graph_adjacent_list(edge edges[], int n, int nodes_number) {

    nodes_in_graph =  new node*[nodes_number]();

    this->nodes_number = nodes_number;

    int temp_end_vertex=0;

    for (int i = 0 ;i < nodes_number;i++) nodes_in_graph[i] = nullptr;

    for(int  i =0 ;i < n; i++)
    {
        int start_vertex = edges[i].start_vertex;
        int end_vertex = edges[i].end_vertex;
        int used = edges[i].possible_flow;

        if(end_vertex > temp_end_vertex) temp_end_vertex = end_vertex;

        node* temp_node = get_node(end_vertex, used, nodes_in_graph[start_vertex]);

        nodes_in_graph[start_vertex] = temp_node;
    }

    vertice_number = temp_end_vertex;
}

void graph_adjacent_list::load_data(fstream f) {

}

void graph_adjacent_list::print_data()
{
    for (int i = 0; i < nodes_number; i++)
    {
        while (nodes_in_graph[i] != nullptr) {
            cout << "(" << i << ", " << nodes_in_graph[i]->end_vertex
                 << ", " << nodes_in_graph[i]->cost << ") ";
            nodes_in_graph[i] = nodes_in_graph[i]->next_node;
        }
        cout <<"\n";
    }

}

node *graph_adjacent_list::get_node(int end_vertex, int weight, node *nodes)
{
    node* temp_node = new node;
    temp_node->cost = weight;
    temp_node->end_vertex = end_vertex;
    temp_node->next_node = nodes;
    temp_node->used =false;

    return temp_node;
}

graph_adjacent_list::~graph_adjacent_list() {
    for (int i = 0; i < nodes_number; i++) delete[] nodes_in_graph[i];

    delete[] nodes_in_graph;
}

void graph_adjacent_list::find_path() { // returns iterator of last vertex in path

       bool used[vertice_number+1];
       for(int i = 0; i < vertice_number + 1; i++) used[i] = false;

       vector <int> vertice;






}

int graph_adjacent_list::find_max_flow() {

    int max_flow = 0;


    int min_flow_in_path = 9999999;

    return max_flow;
}
