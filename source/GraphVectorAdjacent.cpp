//
// Created by dambr on 25.04.2023.
//

#include "../include/GraphVectorAdjacent.h"
#include <fstream>
#include <iostream>

GraphVectorAdjacent::GraphVectorAdjacent() {
}

GraphVectorAdjacent::~GraphVectorAdjacent() {
    delete[] verticies;
}

void GraphVectorAdjacent::loadData(std::string source, int verticesNumber) {
    //source.insert(0, "../source/");
    std::ifstream stream(source);

    this->graphSize = verticesNumber;
    this->sinkIndex = graphSize - 1;
    verticies = new Vector<Pair<int, int>>[verticesNumber];
    verticeLevel =  new int[graphSize];

    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphSize; j++) {
            int temp;
            stream >> temp;
            if (temp > 0) {
                verticies[i].push(Pair(j,temp));
            }
        }
    }
}

void GraphVectorAdjacent::printGraph() {
    for(int i = 0; i < graphSize; i++)
    {
        std::cout << i << " ";
        for(int j= 0; j<verticies[i].size;j++)
        {
            std::cout <<"("<<i<<","<<verticies[i][j].second<< ","
                      << verticies[i][j].first << ") ";
        }
        std::cout <<"\n";
    }
}

bool GraphVectorAdjacent::bfsSetLevels() {
    for(int i = 0; i < graphSize;i++) verticeLevel[i] = -1;
    verticeLevel[0] = 0;

    Vector <int> moves;
    moves.push(0);

    while(!moves.empty())
    {
        int tempSource = moves[0];
        moves.remove(0);
        for(int i = 0; i < verticies[tempSource].size; i++)
        {
            if(verticeLevel[verticies[tempSource][i].first] < 0 && verticies[tempSource][i].second > 0)
            {
                verticeLevel[verticies[tempSource][i].first] = verticeLevel[tempSource] + 1;
                moves.push(verticies[tempSource][i].first);
                if(verticies[tempSource][i].first == sinkIndex) return true;
            }
        }

    }

    return verticeLevel[sinkIndex] >= 0;
}


int GraphVectorAdjacent::dfsSendFlow(int currentFlow,Vector<int> &path) {
    if(path.top() == sinkIndex) return currentFlow;

    int currentIndex = path.top();

    for(int i = 0;i<verticies[currentIndex].size;i++)
    {
        Pair <int,int> vertex = verticies[currentIndex][i];
        if(verticeLevel[vertex.first] == verticeLevel[currentIndex] + 1 && vertex.second > 0)
        {
            path.push(vertex.first);
            int flow = (currentFlow > vertex.second) ? vertex.second : currentFlow;
            int possibleFlow = dfsSendFlow( flow, path);
            if(possibleFlow>0)
            {
                verticies[currentIndex][i].second-=possibleFlow;
                return possibleFlow;
            }
        }
    }

    return 0;
}

int GraphVectorAdjacent::dinicMaxFlow() {
    int maxFlow=0;
    //for(int i = 0 ; i < graphSize; i++) std::cout << verticeLevel[i] << " ";
    while(bfsSetLevels())
    {
        Vector <int> path;
        path.push(0);
        maxFlow+= dfsSendFlow(100000,path);
    }

    return maxFlow;
}

void GraphVectorAdjacent::loadData(int **matrix, int verticesNumber) {
    this->graphSize = verticesNumber;
    this->sinkIndex = graphSize - 1;
    verticies = new Vector<Pair<int, int>>[verticesNumber];
    verticeLevel =  new int[graphSize];

    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphSize; j++) {
            if (matrix[i][j] > 0) {
                verticies[i].push(Pair(j,matrix[i][j]));
            }
        }
    }
}
