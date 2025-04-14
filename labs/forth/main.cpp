#include "MyVector.h"
#include <chrono>
#include <iostream>
#include <vector>

using namespace std::chrono;

int main() {
    const size_t n = 10000000;  // число элементов (например, 10 миллионов)

    // Создаем большой объект
    MyVector vec1(n);
    
    // Измерение времени копирования
    auto start_copy = high_resolution_clock::now();
    MyVector vec_copy = vec1; // Вызов конструктора копирования
    auto end_copy = high_resolution_clock::now();
    auto duration_copy = duration_cast<milliseconds>(end_copy - start_copy);
    std::cout << "Копирование заняло: " << duration_copy.count() << " мс\n";

    // Создаем временный объект для перемещения
    auto start_move = high_resolution_clock::now();
    MyVector vec_move = std::move(vec1); // Вызов move-конструктора
    auto end_move = high_resolution_clock::now();
    auto duration_move = duration_cast<milliseconds>(end_move - start_move);
    std::cout << "Перемещение заняло: " << duration_move.count() << " мс\n";

    // Дополнительная проверка: можно выводить размеры векторов
    std::cout << "Размер vec_copy: " << vec_copy.getSize() << "\n";
    std::cout << "Размер vec1 (после перемещения): " << vec1.getSize() << "\n";

    return 0;
}