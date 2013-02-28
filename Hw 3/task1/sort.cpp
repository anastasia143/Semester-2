#include "sort.h"

void Sort::swap(int* array, int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void Sort::sortDescending(int* array, int size)
{

    for(int i = 0; i < size / 2; i++)
        swap(array, i, size - 1 - i);
}

