#ifndef SWAP_H
#define SWAP_H

#include <utility> // для std::move

template<typename T>
void mySwap(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

#endif // SWAP_H