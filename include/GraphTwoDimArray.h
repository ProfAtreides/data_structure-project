//
// Created by dambr on 25.04.2023.
//

#pragma once
#include "../include/Vector.h"
#include "Graph.h"
#include <string>

class GraphTwoDimArray : public Graph
{
    int** graphMatrix;
    int* verticeLevel;
    int sinkIndex;
    int size;

    public:
    GraphTwoDimArray();
    void loadData(int** matrix, int size) override;
    void loadData(std::string input, int size) override;
    ~GraphTwoDimArray();
    int dfsSendFlow(int currentFlow,Vector<int> &path);
    bool bfsSetLevels();
    int dinicMaxFlow() override;
};

