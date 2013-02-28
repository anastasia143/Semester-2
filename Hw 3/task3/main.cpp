/**
*@author Semenova Anastasia
*@version 1.0
*This program sorts array with Bubble Sort.
  */

#include <iostream>
#include "arrayFunctions.h"
#include "sort.h"
using namespace std;

/*
Reminder:
n - lines
m - columns
*/

int main()
{
    int n = 0;
    int m = 0;
    cout << "Enter size of array"
         << endl << "n (lines) := ";
    cin >> n;
    cout << "m (columns) := ";
    cin >> m;

    int** array = new int*[n];
    for(int i = 0; i < n; i++)
       array[i] = new int[m];

    fill(array, n, m);
    cout << endl << "Sourse array:" << endl;
    print(array, n, m);

    cout << endl << "Sorted array: " << endl;
    sort(array, n, m);
    print(array, n, m);

    for(int i = 0; i < n; i++)
       delete[] array[i];
    delete[] array;
    
    return 0;
}
