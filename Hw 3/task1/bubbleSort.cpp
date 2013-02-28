#include <iostream>
#include "bubbleSort.h"

void BubbleSort::sortAscending(int* array, int size)
{
    for (int i = 0; i < size - 1; i++)
        {
            for (int k = 0; k < size - i; k++)
            {
                if (array[k] > array[k + 1])
                    swap(array, k, k + 1);
            }
        }
}


