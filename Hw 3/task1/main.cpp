/**
*@author Semenova Anastasia
*@version 1.0
*/

#include <iostream>
#include "bubbleSort.h"
#include "quickSort.h"
#include "insertSort.h"
#include "arrayFunctions.h"
#include "createSort.h"
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
        Sort* sort = createSort(algorithm);
        sort->sortAscending(array, size);
        if (order == 2)
            sort->sortDescending(array, size);
        delete sort;
        print(array, size);
        cout << endl << endl << "Enter sort algorithm: ";
        cin >> algorithm;
        cout << "Ascending or descending (1 or 2)? ";
        cin >> order;
    }
    delete[] array;

    return 0;
}
