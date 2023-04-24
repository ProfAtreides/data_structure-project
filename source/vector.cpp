//
// Created by Dawid on 24.04.2023.
//

#include "vector.h"

template <typename T>
vector<T>::vector(){
    size = 0;
    capacity = 2;
    data = new T[capacity];
}

template <typename T>
vector<T>::~vector(){
    delete []data;
}

template <typename T>
bool vector<T>::push(T val) {
    if (size == capacity) {
        T* temp = new T[capacity * 2];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity *= 2;
    }
    data[size] = val;
    size++;
}

template <typename T>
bool vector<T>::pop() {
    size = (size > 0)?size--:0;
}

template <typename T>
T& vector<T>::operator [](int n)
{
    return data[n];
}