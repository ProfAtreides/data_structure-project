//
// Created by Dawid on 24.04.2023.
//
#pragma once
#ifndef STRUKTURY_DANYCH_VECTOR_H
#define STRUKTURY_DANYCH_VECTOR_H

template <typename T>
struct vector {
    T* data;
    int size,capacity;
    vector();
    ~vector();
    void push(T val);
    void remove(int index);
    void remove(int index,int amount);
    void clear();
    bool empty();
    T top();
    T& operator [](int n);
};


#endif //STRUKTURY_DANYCH_VECTOR_H
