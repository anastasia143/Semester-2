#include <cstdlib>
#include <iostream>
#include "arrayFunctions.h"
using namespace std;

/*
Reminder:
n - lines
m - columns
*/

void print(int** array, int n, int m)
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < m; i++)
            cout << array[k][i] << " ";
        cout << endl;
    }
}

void fill(int **array, int n, int m)
{
    for(int k = 0; k < n; k++)
        for(int i = 0; i < m; i++)
            array[k][i] = rand() % 10;
}
