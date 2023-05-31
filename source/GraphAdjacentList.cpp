//
// Created by dambr on 16.04.2023.
//

#include "../include/GraphAdjacentList.h"
#include <iostream>

GraphAdjacentList::GraphAdjacentList() {
}

void GraphAdjacentList::loadData(std::string fileName, int verticesNumber) {
    //fileName.insert(0, "../source/");
    std::fstream stream(fileName);

    this->graphSize = verticesNumber;

    Vector<Edge> storage;

    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphSize; j++) {
            int temp;
            stream >> temp;
            if (temp > 0) {
                storage.push({i, j, temp});
            }
        }
    }

    stream.close();

    int nodesNumber = storage.size;

    nodesInGraph = new Node *[graphSize]();

    verticesLevel = new int[graphSize];

    sinkIndex = graphSize - 1;

    for (int i = 0; i < graphSize; i++) nodesInGraph[i] = nullptr;

    for (int i = 0; i < nodesNumber; i++) {
        int start_vertex = storage[i].startVertex;
        int end_vertex = storage[i].endVertex;
        int used = storage[i].possibleFlow;

        Node *tempNode = new Node;
        tempNode->startVertex = start_vertex;
        tempNode->capacity = used;
        tempNode->endVertex = end_vertex;
        tempNode->nextNode = nodesInGraph[start_vertex];
        tempNode->flow = 0;

        nodesInGraph[start_vertex] = tempNode;
    }

}

void GraphAdjacentList::loadData(int **matrix, int verticesNumber) {
    this->graphSize = verticesNumber;
    Vector<Edge> storage;
    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphSize; j++) {
            if (matrix[i][j] > 0) {
                storage.push({i, j, matrix[i][j]});
            }
        }
    }

    int nodesNumber = storage.size;

    nodesInGraph = new Node *[graphSize]();

    verticesLevel = new int[graphSize];

    sinkIndex = graphSize - 1;

    for (int i = 0; i < graphSize; i++) nodesInGraph[i] = nullptr;

    for (int i = 0; i < nodesNumber; i++) {
        int start_vertex = storage[i].startVertex;
        int end_vertex = storage[i].endVertex;
        int used = storage[i].possibleFlow;

        Node *tempNode = new Node;
        tempNode->startVertex = start_vertex;
        tempNode->capacity = used;
        tempNode->endVertex = end_vertex;
        tempNode->nextNode = nodesInGraph[start_vertex];
        tempNode->flow = 0;

        nodesInGraph[start_vertex] = tempNode;
    }

}

GraphAdjacentList::~GraphAdjacentList() {
}

void GraphAdjacentList::printGraph() const {
    for (int i = 0; i < graphSize; i++) {
        Node *temp = nodesInGraph[i];
        std::cout << i << " ";
        while (temp != nullptr) {
            std::cout << "(" << temp->startVertex
                      << ", " << temp->capacity << ", "
                      << temp->endVertex << ") ";
            temp = temp->nextNode;
        }
        std::cout << "\n";
    }

}

bool GraphAdjacentList::bfsAssignLevels() {
    for (int i = 0; i < graphSize; i++) verticesLevel[i] = -1;

    verticesLevel[0] = 0;

    Vector<Node *> moves;
    moves.push(&nodesInGraph[0][0]);

    while (!moves.empty()) {
        Node *temp = moves.top();
        moves.remove(moves.size-1);
        while (temp != nullptr) {
            if (verticesLevel[temp->endVertex] < 0 && temp->flow < temp->capacity) {
                verticesLevel[temp->endVertex] = verticesLevel[temp->startVertex] + 1;

                if (temp->endVertex == sinkIndex) {
                    return true;
                }

                moves.push(&nodesInGraph[temp->endVertex][0]);
            }
            temp = temp->nextNode;
        }
    }

    return verticesLevel[sinkIndex] >= 0;
}

int GraphAdjacentList::dfsSendFlow(int currentIndex, int currentFlow, Vector<Node*> *path) {
    if (currentIndex == sinkIndex) return currentFlow;

    Node *temp = path->top();

    while (temp != nullptr) {
        if (verticesLevel[temp->startVertex] + 1 == verticesLevel[temp->endVertex] &&
            temp->flow < temp->capacity) {
            path->push(&nodesInGraph[temp->endVertex][0]);
            int flow = (currentFlow > temp->capacity - temp->flow) ? temp->capacity - temp->flow : currentFlow;
            int possibleFlow = dfsSendFlow(temp->endVertex,flow,path);
            if(possibleFlow > 0)
            {
                temp->flow += possibleFlow;
                return possibleFlow;
            }

        }
        temp = temp->nextNode;
    }

    return 0;
}

int GraphAdjacentList::dinicMaxFlow() {
    int maxFlow = 0;
    int i = 0;
    while(bfsAssignLevels())
    {
        Vector <Node*> path;
        path.push(&nodesInGraph[0][0]);
        maxFlow+= dfsSendFlow(0,100000,&path);
    //   std::cout << maxFlow << " ";
    }
    return maxFlow;
}







