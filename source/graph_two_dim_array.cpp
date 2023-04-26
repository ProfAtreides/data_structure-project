//
// Created by dambr on 25.04.2023.
//

//Bilio
//https://www.softwaretestinghelp.com/graph-implementation-cpp/

#include "graph_two_dim_array.h"

graph_two_dim_array::graph_two_dim_array(int size) {
    this->size = size;
    graph_matrix = new int*[size];
    for(int i = 0; i < size;i++)
    {
        graph_matrix[i] = new int[size];
    }
}

void graph_two_dim_array::load_data() {
    for(int i = 0; i < size;i++)
    {
        delete graph_matrix[i];
    }
    delete []graph_matrix;
}

void graph_two_dim_array::bfs() {

    vector <vector<int>> path;
    path.push(vector<int>());

    while(path.size>0)
    {
        for(int i=0;i<path.size;i++)
        {
            bool moved_forward = false;
            for(int j = 0; j < size; j++)
            {
                if(graph_matrix[path[i].top()][j] > 0 || !moved_forward)
                {
                    path[i].push(j);
                    moved_forward = true;
                }
                else if(graph_matrix[path[i].top()][j] > 0 || moved_forward)
                {
                    path.push(path[i]);
                    path[size-1].push(j);
                }
            }
            if(!moved_forward) path.remove(i);
        }
    }
}

int graph_two_dim_array::find_max_flow(vector<vector<int>> path) {

}

