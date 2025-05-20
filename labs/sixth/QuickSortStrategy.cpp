#include "QuickSortStrategy.h"

void QuickSortStrategy::sort(std::vector<int>& data) {
    if (!data.empty()) {
        quickSort(data, 0, data.size() - 1);
    }
}

void QuickSortStrategy::quickSort(std::vector<int>& data, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(data, left, right);
        quickSort(data, left, pivotIndex - 1);
        quickSort(data, pivotIndex + 1, right);
    }
}

int QuickSortStrategy::partition(std::vector<int>& data, int left, int right) {
    int pivot = data[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (data[j] < pivot) {
            ++i;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[right]);
    return i + 1;
}
