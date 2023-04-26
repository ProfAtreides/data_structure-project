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

    return temp_node;
}

graph_adjacent_list::~graph_adjacent_list() {
    for (int i = 0; i < nodes_number; i++) delete[] nodes_in_graph[i];

    delete[] nodes_in_graph;
}

void graph_adjacent_list::find_paths() { // returns iterator of last vertex in path

       bool used_vertices[vertice_number+1];
       used_vertices[0] = true;
       for(int i = 0; i < vertice_number + 1; i++) used_vertices[i] = false;

       vector <vector<node>> possible_paths;
       possible_paths.push(vector<node>());
       possible_paths[0].push(*nodes_in_graph[0]);

       while(possible_paths.size > 0)
       {
           for(int i = 0; i < possible_paths.size;i++)
           {
               node temp_node = *possible_paths[i].top().next_node;
               if(used_vertices[temp_node.end_vertex]) possible_paths.remove(i);
               if()
           }
       }
}



int graph_adjacent_list::find_max_flow(vector <node> path) {

    int max_flow = 247181;

    for(int i =0; i< path.size;i++)
    {
        if(max_flow>path[i].cost) max_flow = path[i].cost;
    }

    return max_flow;
}

int graph_adjacent_list::ford(){

}