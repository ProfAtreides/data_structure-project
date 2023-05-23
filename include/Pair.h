//
// Created by Dawid on 26.04.2023.
//

template <typename T, typename Y>
class Pair{
public:
    T first;
    Y second;
    Pair();
    Pair(T first, Y second);
};

template<typename T,typename Y>
Pair<T,Y>::Pair()
= default;

template<typename T,typename Y>
Pair<T,Y>::Pair(T first, Y second) {
    this->first = first;
    this->second = second;
}


