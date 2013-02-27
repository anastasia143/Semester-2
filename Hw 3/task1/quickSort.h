#pragma once
#include "sort.h"

class QuickSort : public Sort
{
public:
    QuickSort();
    void sortAscending(int* array, int size);
    void sortDescending(int* array, int size);
private:
    /**
*@quickSortAscending
*@quickSortDescending
*main sorting methods that are caused by @sortAscending and @sortDescending
*/
    void quickSortAscending(int* array, int start, int end);
    void quickSortDescending(int* array, int start, int end);
};
