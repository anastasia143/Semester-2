#pragma once
#include "sort.h"

class BubbleSort : public Sort
{
public:
    BubbleSort();
    void sortAscending(int *array, int size);
    void sortDescending(int *array, int size);
};

