#include <cstdlib>
#include <iostream>
#include "arrayFunctions.h"
using namespace std;

void print(int* array, int size)
{
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";
}

void fill(int* array, int size)
{
    for(int i = 0; i < size; i++)
        array[i] = rand() % 25;
}
