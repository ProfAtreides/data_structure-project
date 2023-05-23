//
// Created by Dawid on 24.04.2023.
//

#pragma once

template <typename T>
class Vector {
public:
    T* data;
    long long size,capacity;
    Vector();
    ~Vector();
    void push(T val);
    void resize(int size);
    void remove(int index);
    void remove(int index,int amount);
    void clear();
    bool empty();
    T top();
    T& operator [](int n);
};

template<typename T>
Vector<T>::Vector() {
    size = 0;
    capacity = 2;
    data = new T[capacity];
}

template <typename T>
Vector<T>::~Vector(){
    delete []data;
}

template <typename T>
void Vector<T>::push(T val) {
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
void Vector<T>::remove(int index) {
    for(int i =index;i < size - 1;i++)
    {
        data[i] = data[i+1];
    }
    size--;
}

template <typename T>
void Vector<T>::remove(int index, int amount) {
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
void Vector<T>::clear(){
    size=0;
    capacity=1;
    data = new T[capacity];
}

template <typename T>
bool Vector<T>::empty() {
    if(size == 0) return true;
    else return false;
}

template <typename T>
T Vector<T>::top()
{
    return data[size-1];
}

template <typename T>
T& Vector<T>::operator [](int n)
{
    return data[n];
}

template<typename T>
void Vector<T>::resize(int size) {
    this->size = size;
    T* temp = new T[capacity * 2];
    for (int i = 0; i < size; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity = (size >0)? size+2:1;
}
