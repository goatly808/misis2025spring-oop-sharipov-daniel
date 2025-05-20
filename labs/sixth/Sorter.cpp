#include "Sorter.h"

Sorter::Sorter(SortingStrategy* strategy) : strategy_(strategy) {}

void Sorter::sortData(std::vector<int>& data) {
    strategy_->sort(data);
}

void Sorter::setStrategy(SortingStrategy* strategy) {
    strategy_ = strategy;
}
