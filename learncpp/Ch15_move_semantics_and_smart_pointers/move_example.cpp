#include <iostream>
#include <string>
#include <utility>

template<class T>
void myswap(T& a, T& b) {
    T tmp {std::move(a)}
    a = std::move(b);
    b = std::move(tmp);
}