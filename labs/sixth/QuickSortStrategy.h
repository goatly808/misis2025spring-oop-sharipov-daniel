#ifndef QUICKSORTSTRATEGY_H
#define QUICKSORTSTRATEGY_H

#include "SortingStrategy.h"

class QuickSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override;
private:
    void quickSort(std::vector<int>& data, int left, int right);
    int partition(std::vector<int>& data, int left, int right);
};

#endif // QUICKSORTSTRATEGY_H
