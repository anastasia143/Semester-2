#pragma once

/**
*@class Sort
*class with sorting array methods and help function
*/

class Sort
{
public:
    /**
*@sortAscending
*vitual method for Bubble Sort, Insert Sort, Quick Sort
*@sortDescending
*method that reverses array
*/
    virtual void sortAscending(int* array, int size) = 0;
    void sortDescending(int* array, int size);
protected:
    /**
*@swap
*method that interchanges 2 elements of array
*/
    void swap(int* array, int a, int b);
};
