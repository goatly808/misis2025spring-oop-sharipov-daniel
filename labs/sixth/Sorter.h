#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include "SortingStrategy.h"

class Sorter {
public:
    explicit Sorter(SortingStrategy* strategy);
    void sortData(std::vector<int>& data);
    void setStrategy(SortingStrategy* strategy);
private:
    SortingStrategy* strategy_;
};

#endif // SORTER_H
