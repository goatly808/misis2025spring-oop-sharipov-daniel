#ifndef INSERTIONSORTSTRATEGY_H
#define INSERTIONSORTSTRATEGY_H

#include "SortingStrategy.h"

class InsertionSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override;
};

#endif // INSERTIONSORTSTRATEGY_H
