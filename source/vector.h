//
// Created by Dawid on 24.04.2023.
//

#ifndef STRUKTURY_DANYCH_VECTOR_H
#define STRUKTURY_DANYCH_VECTOR_H

template <typename T>
struct vector {
    T* data;
    int size,capacity;
    vector();
    ~vector();
    bool push(T val);
    bool pop();
    bool clear();
    bool empty();
    T& operator [](int n);
};


#endif //STRUKTURY_DANYCH_VECTOR_H
