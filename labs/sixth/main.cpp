#include <iostream>
#include <vector>
#include "BubbleSortStrategy.h"
#include "QuickSortStrategy.h"
#include "StdSortStrategy.h"
#include "InsertionSortStrategy.h"
#include "Sorter.h"

void printVector(const std::vector<int>& data) {
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> data{5, 2, 9, 1, 5, 6};

    BubbleSortStrategy bubbleSort;
    QuickSortStrategy quickSort;
    StdSortStrategy stdSort;
    InsertionSortStrategy insertionSort;

    Sorter sorter(&bubbleSort);
    std::cout << "Original data: ";
    printVector(data);

    sorter.sortData(data);
    std::cout << "Bubble sorted: ";
    printVector(data);

    data = {5, 2, 9, 1, 5, 6};
    sorter.setStrategy(&quickSort);
    sorter.sortData(data);
    std::cout << "Quick sorted: ";
    printVector(data);

    data = {5, 2, 9, 1, 5, 6};
    sorter.setStrategy(&stdSort);
    sorter.sortData(data);
    std::cout << "Std sorted: ";
    printVector(data);

    data = {5, 2, 9, 1, 5, 6};
    sorter.setStrategy(&insertionSort);
    sorter.sortData(data);
    std::cout << "Insertion sorted: ";
    printVector(data);

    return 0;
}
