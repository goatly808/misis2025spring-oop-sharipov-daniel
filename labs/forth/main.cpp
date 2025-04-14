#include "MyVector.h"
#include "Swap.h"
#include "ContainerToString.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
using namespace std::chrono;

int main() {
    /*
    
    std::string str1 = "Привет";
    std::string str2 = "Мир";
    std::cout << "До обмена: str1 = " << str1 << ", str2 = " << str2 << "\n";
    mySwap(str1, str2);
    std::cout << "После обмена: str1 = " << str1 << ", str2 = " << str2 << "\n"; //проверка работы swap

    */

    /*
    
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<std::string> lst = {"один", "два", "три"};
    std::set<char> st = {'a', 'b', 'c'};

    std::cout << "Вектор: " << container_to_string(vec) << "\n";
    std::cout << "Список: " << container_to_string(lst) << "\n";
    std::cout << "Множество: " << container_to_string(st) << "\n";   //проверка работы контейнера

    */

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