#include <iostream>
#include <fstream>
#include "../include/vector.h"
#include "../include/graph_two_dim_array.h"

using namespace std;

int main() {
    graph_two_dim_array test_graph("test.txt",6);
    cout<<"Max flow is: " <<test_graph.find_max_flow();
}
