#include "sort.h"

void Sort::swap(int* array, int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}
