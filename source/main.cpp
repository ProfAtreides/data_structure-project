#include <iostream>
#include <fstream>
//#include "graph_adjacent_list.cpp"
#include "graph_two_dim_array.h"

using namespace std;

void load_array(char file_name[], int **array,int size)
{
    ifstream stream(file_name);

    array = new int*[size];

    for(int i =0;i<size;i++)
    {
        array[i] = new int[size];
        for(int j = 0;j<size;j++)
        {
            stream >> array[i][j];
        }
    }
}

int main() {

  /*  edge edges[] = {{0, 1, 11},
                    {0, 2, 12},
                    {1, 3, 12},
                    {2, 1, 1},
                    {2, 4, 11},
                    {4, 5, 4},
                    {4, 3, 7},
                    {3,5,19}
    };
    int N = 8;
    int n = sizeof(edges) / sizeof(edges[0]);

    graph_adjacent_list graph(edges, n, N);

    graph.print_data();
    */

   // int graph[6][6]={ { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
             //       { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
                //        { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
    int **graph;

    graph_two_dim_array test_graph(6, graph);

    cout <<test_graph.find_max_flow();

}
