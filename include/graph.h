//
// Created by dambr on 22.05.2023.
//

#ifndef PROGRAM_GRAPH_H
#include <string>
#define PROGRAM_GRAPH_H

class graph
{
public:
    int size;
    virtual int find_max_flow()=0;
    virtual bool load_data(std::string stream,int size)=0;
    virtual bool bfs()=0;

};

#endif //PROGRAM_GRAPH_H
