#include "sort.h"

/*
Reminder:
n - lines
m - columns
*/

/**
  *@sort
  *Bubble Sort for array that uses helping functions @compare and @swap
  */

void sort(int** array, int n, int m)
{
    for (int i = 0; i < m - 1; i++)
        for (int k = 0; k < m - i - 1; k++)
            if (comparison(array, k, k + 1, n))
                        swap(array, k, k + 1, n);
}

/**
  *@compare
  *check if column1 > column2 (sort by the first value)
  */

bool comparison(int** array, int column1, int column2, int n)
{
    for(int i = 0; i < n; i++)
    {
        if (array[i][column1] < array[i][column2])
            return false;
        if (array[i][column1] > array[i][column2])
            return true;
    }
    return false;
}

/**
  *@swap
  *interchanges two columns
  */

void swap(int** array, int column1, int column2, int n)
{
    for(int i = 0; i < n; i++)
    {
        int temp = array[i][column1];
        array[i][column1] = array[i][column2];
        array[i][column2] = temp;
    }
}
