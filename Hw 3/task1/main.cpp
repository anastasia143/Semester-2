/**
*@author Semenova Anastasia
*@version 1.0
*/

#include <iostream>
#include "sort.h"
#include "bubbleSort.h"
#include "quickSort.h"
#include "insertSort.h"
#include "arrayFunctions.h"
using namespace std;

int main()
{
    cout << "You have array of integer." << endl;
    unsigned int size = 10;
    int* array = new int[size];
    fill(array, size);
    print(array, size);

    cout << endl << "You may sort it with: ";
    cout << endl << "0 - exit"
         << endl << "1 - Bubble Sort"
         << endl << "2 - Quick Sort"
         << endl << "3 - Insert Sort"
         << endl << endl;

    unsigned int algorithm = 8;
    unsigned int order = 3;
    cout << "Enter sort algorithm: ";
    cin >> algorithm;
    cout << "Ascending or descending (1 or 2)? ";
    cin >> order;


    while(algorithm != 0)
    {
        switch(algorithm)
        {
        case 1:
        {
            Sort* sort = new BubbleSort();
            cout << "BUBBLE SORT: ";
            if (order == 1)
                sort->sortAscending(array, size);
            else
                sort->sortDescending(array, size);
            break;
            delete sort;

        }
        case 2:
        {
            Sort* sort = new QuickSort();
            cout << "QUICK SORT: ";
            if (order == 1)
                sort->sortAscending(array, size);
            else
                sort->sortDescending(array, size);
            break;
            delete sort;
        }
        case 3:
        {
            Sort* sort = new InsertSort();
            cout << "INSERT SORT: ";
            if (order == 1)
                sort->sortAscending(array, size);
            else
                sort->sortDescending(array, size);
            break;
            delete sort;
        }
        default:
        {
            algorithm = 0;
            break;
        }
        }
        print(array, size);
        cout << endl << endl << "Enter sort algorithm: ";
        cin >> algorithm;
        if (algorithm == 0)
            break;
        cout << "Ascending or descending (1 or 2)? ";
        cin >> order;
    }

    delete[] array;

    return 0;
}
