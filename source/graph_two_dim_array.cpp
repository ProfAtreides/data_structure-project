//
// Created by dambr on 25.04.2023.
//

#include <fstream>
#include <iostream>
#include <string>
#include "../include/graph_two_dim_array.h"
#include "../include/vector.h"

//fifo , lifo queue

graph_two_dim_array::graph_two_dim_array(std::string data,int size)
{
    data.insert(0,"../source/");
    std::ifstream stream(data);
    graph_matrix = new int*[size];
    this->size = size;

    for(int i =0;i<size;i++)
    {
        graph_matrix[i] = new int[size];
        for(int j = 0;j<size;j++)
        {
           stream >>  graph_matrix[i][j];
        }
    }

}


graph_two_dim_array::~graph_two_dim_array()
{
    for(int i = 0; i < size;i++)
    {
        delete[] graph_matrix[i];
    }
    delete[] graph_matrix;
}

bool graph_two_dim_array::bfs(int **resudal_matrix,int *path)
{
    int end = size-1;
    bool visited[size];
    for(int i =0;i<size;i++) visited[i] = false;

    vector<int> q;
    q.push(0);
    visited[0] = true;
    path[0] = -1;

    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.top();
        q.remove(q.size-1);

        for (int v = 0; v < size; v++) {
            if (!visited[v] && resudal_matrix[u][v] > 0)
            {
                if (v == end)
                {
                    path[v] = u;
                    return true;
                }
                q.push(v);
                path[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}

int graph_two_dim_array::find_max_flow()
{
    int u, v, end = size-1;
    int **resudal_matrix =  new int*[size];
    for(int i =0;i<size;i++)
    {
        resudal_matrix[i] = new int[size];
    }

    for (u = 0; u < size; u++)
    {
        for (v = 0; v < size; v++)
        {
            resudal_matrix[u][v] = graph_matrix[u][v];
        }
    }

    int *path =  new int[size];

    int max_flow = 0;

    while (bfs(resudal_matrix,path))
    {
        int path_flow = INT_MAX;
        for (v = end; v != 0; v = path[v]) {
            u = path[v];
            path_flow = std::min(path_flow, resudal_matrix[u][v]);
        }
        for (v = end; v != 0; v = path[v]) {
            u = path[v];
            resudal_matrix[u][v] -= path_flow;
            resudal_matrix[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    delete[] path;
    return max_flow;
}

graph_two_dim_array::graph_two_dim_array() {
    size = 0;
    graph_matrix = new int*[0];
}

