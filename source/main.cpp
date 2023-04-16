#include <iostream>
#include "first_graph.h"
//#include <murder_me_in_my_sleep>
//using should_have_studied_something_fun=NOT(PROGRAMMING)

using namespace std;

void display_AdjList(node* ptr, int i)
{
    while (ptr != nullptr) {
        cout << "(" << i << ", " << ptr->value
             << ", " << ptr->cost << ") ";
        ptr = ptr->next_node;
    }
    cout << endl;
}

int main() {
    edge edges[] = {{0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}};

    int N = 6;
    int n = sizeof(edges) / sizeof(edges[0]);

    first_graph graph(edges,n,N);

   graph.print_data();

    return 0;
}
