#include <iostream>
#include "createSort.h"
#include "insertSort.h"
#include "quickSort.h"
#include "bubbleSort.h"
using namespace std;

Sort* createSort(int algoritm)
{
    switch(algoritm)
    {
    case 1:
    {
        cout << "BUBBLE SORT: ";
        return new BubbleSort();
        break;
    }
    case 2:
    {
        cout << "QUICK SORT: ";
        return new QuickSort();
        break;
    }
    case 3:
    {
        cout << "INSERT SORT: ";
        return new InsertSort();
        break;
    }
    }
}
