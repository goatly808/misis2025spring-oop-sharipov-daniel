#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <algorithm>
#include <cstddef>
#include <iostream>

class MyVector {
private:
    size_t size;
    int* data;

public:
    // Конструктор с выделением памяти под n элементов
    MyVector(size_t n)
        : size(n), data(new int[n]()) {
        std::cout << "Конструктор (" << size << ")\n";
    }

    // Деструктор
    ~MyVector() {
        delete[] data;
        std::cout << "Деструктор\n";
    }

    // Конструктор копирования (глубокое копирование)
    MyVector(const MyVector& other)
        : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + other.size, data);
        std::cout << "Конструктор копирования\n";
    }

    // Оператор копирующего присваивания
    MyVector& operator=(const MyVector& other) {
        std::cout << "Оператор копирующего присваивания\n";
        if (this != &other) {
            // Освобождаем старую память
            delete[] data;

            // Копируем данные
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + other.size, data);
        }
        return *this;
    }

    // Move-конструктор (перемещает ресурсы от временного объекта)
    MyVector(MyVector&& other) noexcept
        : size(other.size), data(other.data) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move-конструктор\n";
    }

    // Move-оператор присваивания
    MyVector& operator=(MyVector&& other) noexcept {
        std::cout << "Move-оператор присваивания\n";
        if (this != &other) {
            delete[] data; // Освобождаем текущие ресурсы

            // Переносим данные и размер
            size = other.size;
            data = other.data;

            // Обнуляем исходный объект
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    // Метод для доступа к элементу по индексу
    int& operator[](size_t index) {
        return data[index];
    }

    const int& operator[](size_t index) const {
        return data[index];
    }

    // Метод для получения размера вектора
    size_t getSize() const { return size; }
};

#endif // MYVECTOR_H