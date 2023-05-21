//
// Created by Dawid on 26.04.2023.
//

template <typename T, typename Y>
class pair {
public:
    T first;
    Y second;
    pair(T first, Y second);
};

template<typename T,typename Y>
pair<T,Y>::pair(T first, Y second) {
    this->first = first;
    this->second = second;
}