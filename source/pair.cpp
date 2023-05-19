//
// Created by Dawid on 26.04.2023.
//

#include "pair.h"

template<typename T,typename Y>
pair<T,Y>::pair(T first, Y second) {
    this->first = first;
    this->second = second;
}