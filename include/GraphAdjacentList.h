//
// Created by dambr on 16.04.2023.
//

#pragma once
#include "Vector.h"
#include "Graph.h"
#include <fstream>

struct Node{
    int startVertex,endVertex,capacity,flow;
    Node* nextNode;
    Node()
    {
        startVertex = -1;
        endVertex = -1;
        capacity = -1;
        flow = -1;
        nextNode = nullptr;
    }
};

struct Edge{
    int startVertex;
    int endVertex;
    int possibleFlow;
};


class GraphAdjacentList : public Graph {
    int graphSize;
    int sinkIndex;
    int* verticesLevel;
    Node** nodesInGraph;

public:
    GraphAdjacentList();
    ~GraphAdjacentList();

    void loadData(int** matrix,int verticesNumber) override;
    void loadData(std::string fileName,int verticesNumber) override;
    Node* getNode(int startVertex,int end_vertex, int weight, Node *nodes);

    void printGraph() const;

    bool bfsAssignLevels(); //returns false if sink wasn't reached
    int dfsSendFlow(int currentIndex,int currentFlow,Vector<Node*> *path);
    int dinicMaxFlow() override;
};






