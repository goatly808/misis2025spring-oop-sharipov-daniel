#ifndef STDSORTSTRATEGY_H
#define STDSORTSTRATEGY_H

#include "SortingStrategy.h"

class StdSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override;
};

#endif // STDSORTSTRATEGY_H
