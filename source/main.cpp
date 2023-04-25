#include <iostream>
#include "graph_adjacent_list.h"
//#include <pain>
//#include <suffering>

//using nothing_useful

using namespace std;

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

    cout << graph.find_max_flow()<<"\n";
    graph.print_data();
    return 0;

}
