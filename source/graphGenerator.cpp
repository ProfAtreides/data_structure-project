#pragma once
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>

void generateNodes(int startIndex, int endIndex, int **graphMatrix, int nodesPerVertex, bool *generated) {
    generated[startIndex] = true;

    if (startIndex == endIndex) return;

    for (int i = 0; i < nodesPerVertex;) {
        int nextVertex = rand() % endIndex + 1;
        int temp = graphMatrix[startIndex][nextVertex];
        if (nextVertex != startIndex && graphMatrix[startIndex][nextVertex] == 0) {
            int tempCapacity = rand() % 100 + 1;
            graphMatrix[startIndex][nextVertex] = tempCapacity;
            i++;
        }
    }
    for (int i = 0; i < endIndex + 1; i++) {
        if (graphMatrix[startIndex][i] > 0 && generated[i] == false) {
            generateNodes(i, endIndex, graphMatrix, nodesPerVertex, generated);
        }
    }
}

void generateGraphsTxt(int currentNumber, int lastNumber, int increasePer, float intensity, std::string sampleName) {
    std::ofstream output(sampleName);
    while (currentNumber < lastNumber + 1) {

        int **graphMatrix;
        graphMatrix = new int *[currentNumber];
        for (int i = 0; i < currentNumber; i++) {
            graphMatrix[i] = new int[currentNumber];
            for (int j = 0; j < currentNumber; j++) {
                graphMatrix[i][j] = 0;
            }
        }

        int maxNodesPerVertex = std::ceil(intensity * currentNumber);
        if (maxNodesPerVertex == currentNumber - 1) maxNodesPerVertex--;

        bool *generated = new bool[currentNumber];
        for (int i = 0; i < currentNumber; i++) generated[i] = false;

        generateNodes(0, currentNumber - 1, graphMatrix, maxNodesPerVertex, generated);

        output << currentNumber << "\n";

        for (int i = 0; i < currentNumber; i++) {
            for (int j = 0; j < currentNumber; j++) {
                output << graphMatrix[i][j] << " ";
            }
            output << "\n";
        }
        currentNumber += increasePer;
    }
    output.close();
}

int** generateGraphMatrix(int seed, int numberOfVertices, float intensity){
    int **graphMatrix;
    srand(seed);
    graphMatrix = new int *[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++) {
        graphMatrix[i] = new int[numberOfVertices];
        for (int j = 0; j < numberOfVertices; j++) {
            graphMatrix[i][j] = 0;
        }
    }

    int maxNodesPerVertex = std::ceil(intensity * numberOfVertices);
    if (maxNodesPerVertex == numberOfVertices - 1) maxNodesPerVertex--;

    bool *generated = new bool[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++) generated[i] = false;

    generateNodes(0, numberOfVertices - 1, graphMatrix, maxNodesPerVertex, generated);
    return graphMatrix;
}

/*int main() {
    //float optimistic = 0.2;
    //float realistic = 0.4;
    //float pessimistic = 0.8;
    srand(SEED);

    generateGraphs(10, 200, 5, 0.2, "test_opt.txt");
    generateGraphs(10, 200, 5, 0.4, "test_rel.txt");
    generateGraphs(10, 200, 5, 0.8, "test_pes.txt");

    generateGraphs(10, 1100, 100, 0.2, "crashtestopt.txt");
    generateGraphs(10, 1100, 100, 0.4, "crashtestrel.txt");
    generateGraphs(10, 1100, 100, 0.8, "crashtestpes.txt");
}*/