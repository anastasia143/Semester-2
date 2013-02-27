#include "insertSort.h"

InsertSort::InsertSort()
{
}

void InsertSort::sortAscending(int* array, int size)
{
    int temp, item;
        for (int counter = 1; counter < size; counter++)
        {
            temp = array[counter];
            item = counter - 1;
            while(item >= 0 && array[item] > temp)
            {
                array[item + 1] = array[item];
                array[item] = temp;
                item--;
            }
        }
}
void InsertSort::sortDescending(int* array, int size)
{
    int temp, item;
        for (int counter = 1; counter < size; counter++)
        {
            temp = array[counter];
            item = counter - 1;
            while(item >= 0 && array[item] < temp)
            {
                array[item + 1] = array[item];
                array[item] = temp;
                item--;
            }
        }

}
