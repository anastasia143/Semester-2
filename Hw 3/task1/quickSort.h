#pragma once
#include "sort.h"

class QuickSort : public Sort
{
public:
    void sortAscending(int* array, int size);
private:
    /**
*@quickSortAscending
*main sorting method that is caused by @sortAscending
*/
    void quickSortAscending(int* array, int start, int end);
};
