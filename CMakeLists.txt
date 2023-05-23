cmake_minimum_required(VERSION 3.23)
project(program)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

set(SOURCES
        source/GraphTwoDimArray.cpp source/GraphVectorAdjacent.cpp source/GraphAdjacentList.cpp
        source/main.cpp)

add_executable(program ${SOURCES})

add_executable(randomiser source/graphGenerator.cpp)



