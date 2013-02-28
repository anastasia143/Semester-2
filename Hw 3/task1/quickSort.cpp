#include "quickSort.h"

void QuickSort::sortAscending(int* array, int size)
{
    quickSortAscending(array, 0, size - 1);
}

void QuickSort::quickSortAscending(int* array, int start, int end)
{
    int a = start;
    int b = end;

    int x = array[(start + end) / 2];

    while (a <= b)
    {
        while (array[a] < x)
        {
            a++;
        }
        while (array[b] > x)
        {
            b--;
        }
        if (a <= b)
        {
            swap(array, a, b);
            a++;
            b--;
        }
    }

    if (a < end)
    {
        quickSortAscending(array, a, end);
    }
    if (start < b)
    {
        quickSortAscending(array, start, b);
    }
}

