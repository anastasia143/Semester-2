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
*@sortDescending
*vitual methods for Bubble Sort, Insert Sort, Quick Sort
*/
    virtual void sortAscending(int* array, int size) = 0;
    virtual void sortDescending(int* array, int size) = 0;
protected:
    /**
*@swap
*method that interchanges 2 elements of array
*/
    void swap(int* array, int a, int b);
};
