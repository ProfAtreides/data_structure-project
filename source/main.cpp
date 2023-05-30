#include <iostream>
#include <fstream>
#include "../include/Vector.h"
#include "../include/GraphAdjacentList.h"
#include "../include/GraphVectorAdjacent.h"
#include "../include/GraphTwoDimArray.h"
#include "graphGenerator.cpp"
#include <chrono>

void testTxt(Graph *graph, std::string input, std::string output) {

    std::fstream inputStream(input);
    std::ofstream outputStream(output);
    int testsNumber = 1;
    while (!inputStream.eof()) {
        std::ofstream copyDataFromSource("../source/temp.txt");
        int verticesNumber;
        int temp;
        long long avgTime = 0;
        inputStream >> verticesNumber;
        std::string line;
        std::getline(inputStream, line);
        for (int i = 0; i < verticesNumber; i++) {
            std::getline(inputStream, line);
            copyDataFromSource << line << "\n";
        }
        copyDataFromSource.close();

        std::string tempInput = "../source/temp.txt";

        std::cout << verticesNumber << " ";

        for (int i = 0; i < testsNumber; i++) {
            graph->loadData(tempInput, verticesNumber);
            auto startTimer = std::chrono::high_resolution_clock::now();
            // std::cout << graph->dinicMaxFlow()<< " ";
            graph->dinicMaxFlow();
            auto stopTimer = std::chrono::high_resolution_clock::now();
            avgTime += (duration_cast<std::chrono::microseconds>(stopTimer - startTimer)).count();
        }
        std::cout << avgTime << "\n";
        outputStream << verticesNumber << " " << avgTime / testsNumber << "\n";
        if (verticesNumber == 200) break;
    }
    outputStream.close();
    inputStream.close();
}

void test(Graph *graph, std::string output, int currentNumber, int endNumber, int increase, int seed,float intensity) {
    std::ofstream outputStream(output);
    for (; currentNumber < endNumber + 1; currentNumber += increase) {
        int testsNumber = 1;
        int temp;
        long long avgTime = 0;
        for (int i = 0; i < testsNumber; i++) {
            graph->loadData(generateGraphMatrix(seed,currentNumber,intensity), currentNumber);
            auto startTimer = std::chrono::high_resolution_clock::now();
           // std::cout << graph->dinicMaxFlow()<< " ";
            graph->dinicMaxFlow();
            auto stopTimer = std::chrono::high_resolution_clock::now();
            avgTime += (duration_cast<std::chrono::microseconds>(stopTimer - startTimer)).count();
        }
        std::cout << currentNumber << "\n";
        outputStream << currentNumber << " " << avgTime / testsNumber << "\n";
    }
    outputStream.close();
}


void speedtestBenchmarkGraph(Graph *graph, std::string output, int seed) {
    std::string optOutput = "../TestResults/" + output + "Opt/" + std::to_string(seed) + ".txt";
    std::string relOutput = "../TestResults/" + output + "Rel/" + std::to_string(seed) + ".txt";
    std::string pesOutput = "../TestResults/" + output + "Pes/" + std::to_string(seed) + ".txt";
    test(graph, relOutput, 10,200,10,seed,0.2);
    test(graph, pesOutput,10 , 200, 10,seed,0.4);
    test(graph, pesOutput,10 , 200, 10,seed,0.8);
}

int main() {

    GraphAdjacentList graph1;
    GraphTwoDimArray graph2;
    GraphVectorAdjacent graph3;
    int seed=77;
    for(int i = 0; i<1;i++,seed+=11)
    {
        speedtestBenchmarkGraph(&graph1, "AL",seed);
        speedtestBenchmarkGraph(&graph2, "TDA",seed);
        speedtestBenchmarkGraph(&graph3, "VA",seed);
    }
}
