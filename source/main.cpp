#include <iostream>
#include "graph_adjacent_list.h"

using namespace std;

//https://www.techiedelight.com/graph-implementation-c-without-using-stl/

int main() {

    edge edges[] = {{0, 1, 11},
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
    return 0;

}
