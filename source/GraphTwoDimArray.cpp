//
// Created by dambr on 25.04.2023.
//

#include <iostream>
#include <fstream>
#include "../include/GraphTwoDimArray.h"


//fifo , lifo queue

GraphTwoDimArray::GraphTwoDimArray()
{
    this->sinkIndex = size - 1;
    this->size = -1;

}


GraphTwoDimArray::~GraphTwoDimArray()
{
    for(int i = 0; i < size;i++)
    {
        delete[] graphMatrix[i];
    }
    delete[] graphMatrix;
}

int GraphTwoDimArray::dfsSendFlow(int currentFlow,Vector<int> &path) {
    if(path.top() == sinkIndex) return currentFlow;

    int currentIndex = path.top();

    for(int i = 0; i<size;i++)
    {
        if(verticeLevel[currentIndex]+1 == verticeLevel[i] && graphMatrix[currentIndex][i]>0)
        {
            path.push(i);
            int flow = (currentFlow > graphMatrix[currentIndex][i]) ? graphMatrix[currentIndex][i] : currentFlow;
            int possibleFlow = dfsSendFlow(flow,path);
            if(possibleFlow>0)
            {
                graphMatrix[currentIndex][i] -= possibleFlow;
                return possibleFlow;
            }
        }
    }

    return 0;
}

bool GraphTwoDimArray::bfsSetLevels() {

    for(int i = 0; i < size;i++) verticeLevel[i] = -1;
    verticeLevel[0]=0;

    Vector <int> moves;
    moves.push(0);

    while(!moves.empty())
    {
        int tempSource = moves[0];
        moves.remove(0);
        for(int i = 0; i < size;i++)
        {
            if(verticeLevel[i] < 0 && graphMatrix[tempSource][i] > 0)
            {
                verticeLevel[i] = verticeLevel[tempSource]+1;
                moves.push(i);
                if(i == sinkIndex) return true;
            }
        }
    }

    return verticeLevel[sinkIndex]>=0;
}

int GraphTwoDimArray::dinicMaxFlow() {

    int maxFlow =0;
    //for(int i = 0; i < size;i++) std::cout << verticeLevel[i]<< " ";
    while(bfsSetLevels())
    {
        Vector <int> path;
        path.push(0);
        maxFlow+= dfsSendFlow(100000,path);
    }
    return maxFlow;
}

void GraphTwoDimArray::loadData(std::string input, int size) {
    this->graphMatrix = new int*[size];
    this->sinkIndex = size - 1;
    this->verticeLevel = new int[size];
    this->size = size;

   // input.insert(0, "../source/");
    std::fstream data(input);

    for(int i =0;i<size;i++)
    {
        graphMatrix[i] = new int[size];
        for(int j = 0;j<size;j++)
        {
            data >> graphMatrix[i][j];
        }
    }
    data.close();
}

void GraphTwoDimArray::loadData(int **matrix, int size) {
    this->graphMatrix = matrix;
    this->sinkIndex = size-1;
    this->verticeLevel = new int[size];
    this->size=size;
}



