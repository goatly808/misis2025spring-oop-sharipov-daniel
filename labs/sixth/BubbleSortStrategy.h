#ifndef BUBBLESORTSTRATEGY_H
#define BUBBLESORTSTRATEGY_H

#include "SortingStrategy.h"

class BubbleSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override;
};

#endif // BUBBLESORTSTRATEGY_H
