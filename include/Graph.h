//
// Created by dambr on 28.05.2023.
//

#ifndef PROGRAM_GRAPH_H
#include <string>
#define PROGRAM_GRAPH_H

class Graph{
public:
    virtual int dinicMaxFlow() = 0;
    virtual void loadData(int** matrix, int verticesNumber)=0;
    virtual void loadData(std::string input, int verticesNumber)=0;
};

#endif //PROGRAM_GRAPH_H
