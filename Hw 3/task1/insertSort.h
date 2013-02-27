#pragma once
#include "sort.h"

class InsertSort : public Sort
{
public:
    InsertSort();
    void sortAscending(int* array, int size);
    void sortDescending(int* array, int size);
};

