#include "BubbleSortStrategy.h"

void BubbleSortStrategy::sort(std::vector<int>& data) {
    bool swapped;
    for (size_t i = 0; i < data.size(); ++i) {
        swapped = false;
        for (size_t j = 1; j < data.size() - i; ++j) {
            if (data[j-1] > data[j]) {
                std::swap(data[j-1], data[j]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
