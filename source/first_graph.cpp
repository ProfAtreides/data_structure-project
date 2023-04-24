//
// Created by dambr on 16.04.2023.
//

#include "first_graph.h"

first_graph::first_graph(edge edges[], int n, int nodes_number) {

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

   end_vertex = temp_end_vertex;
}

void first_graph::load_data(fstream f) {

}

void first_graph::print_data()
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

node *first_graph::get_node(int end_vertex, int weight, node *nodes)
{
    node* temp_node = new node;
    temp_node->cost = weight;
    temp_node->end_vertex = end_vertex;
    temp_node->next_node = nodes;

    return temp_node;
}

first_graph::~first_graph() {
    for (int i = 0; i < nodes_number; i++) delete[] nodes_in_graph[i];

    delete[] nodes_in_graph;
}

bool first_graph::find_path(path &path) { // returns iterator of last vertex in path
    return 0;
}

int first_graph::find_max_flow() {

    int max_flow = 0;

    path path;

    path.add(*nodes_in_graph[0]);


    int min_flow_in_path = 9999999;


    if(!find_path(path)) return -1;

    for(int i = 0; i <path.size;i++)
    {
       if(path.nodes_in_path[i].cost < min_flow_in_path)
       {
           min_flow_in_path = path.nodes_in_path[i].cost;
       }
    }

    max_flow += find_path(path);

    return 0;
}

path::path(){
    nodes_in_path;
    flow_value = 0;
    size = 0;
    end_vertex = 0;
}


void path::print()
{
    for (int i = 0;i <size;i++)
    {
        cout <<nodes_in_path[i].end_vertex << " ";
    }
    cout <<"\n";
}

void path::add(node &n)
{
    nodes_in_path.push(n);
}
