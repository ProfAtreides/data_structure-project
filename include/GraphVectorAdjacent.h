//
// Created by dambr on 25.04.2023.
//


#include "Vector.h"
#include "Pair.h"
#include <string>
#include "Graph.h"


class GraphVectorAdjacent : public Graph {

    //Vector of verticies, each vector has a vector of vertcies(first in pair)
    //adjacent to the vertice with it's node weight
    int graphSize;
    int sinkIndex;
    int* verticeLevel;
    Vector<Pair<int,int>>* verticies;

public:

    GraphVectorAdjacent();
    ~GraphVectorAdjacent();
    void loadData(int** matrix,int verticesNumber) override;
    void loadData(std::string source,int verticesNumber) override;
    void printGraph();

    int dfsSendFlow(int currentFlow,Vector<int> &path);

    bool bfsSetLevels();

    int dinicMaxFlow() override;


};

