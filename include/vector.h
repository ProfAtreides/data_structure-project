//
// Created by Dawid on 24.04.2023.
//

#pragma once

template <typename T>
class vector {
public:
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

template<typename T>
vector<T>::vector() {
    size = 0;
    capacity = 2;
    data = new T[capacity];
}

template <typename T>
vector<T>::~vector(){
    delete []data;
}

template <typename T>
void vector<T>::push(T val) {
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
void vector<T>::remove(int index) {
    for(int i =index;i < size - 1;i++)
    {
        data[i] = data[i+1];
    }
    size--;
}

template <typename T>
void vector<T>::remove(int index, int amount) {
    if(index + amount > size) {
        return;
    }
    for(int i = index;i < size - amount;i++)
    {
        data[i] = data[i+amount];
    }
    size-=amount;
}


template <typename T>
void vector<T>::clear(){
    size=0;
    capacity=1;
    data = new T[capacity];
}

template <typename T>
bool vector<T>::empty() {
    if(size == 0) return true;
    else return false;
}

template <typename T>
T vector<T>::top()
{
    return data[size-1];
}

template <typename T>
T& vector<T>::operator [](int n)
{
    return data[n];
}
