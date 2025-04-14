#ifndef MYARRAY_H
#define MYARRAY_H

#include <cstddef>
#include <stdexcept>

template<typename T, size_t N>
class MyArray {
private:
    T arr[N];

public:
    // Метод для получения размера массива
    constexpr size_t size() const { return N; }

    // Доступ к элементу с проверкой выхода за границы
    T& at(size_t index) {
        if (index >= N) {
            throw std::out_of_range("Индекс вне диапазона");
        }
        return arr[index];
    }

    const T& at(size_t index) const {
        if (index >= N) {
            throw std::out_of_range("Индекс вне диапазона");
        }
        return arr[index];
    }

    // Перегрузка оператора [] (без проверки диапазона)
    T& operator[](size_t index) { return arr[index]; }
    const T& operator[](size_t index) const { return arr[index]; }
};

#endif // MYARRAY_H