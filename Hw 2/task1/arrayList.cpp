#include <iostream>
#include "arrayList.h"
using namespace std;

ArrayList::ArrayList()
{
    array = new int[1000];
    size = 0;
}

void ArrayList::add(int value)
{
    array[size] = value;
    size++;
    return;
}

void ArrayList::remove(int value)
{
    if (size == 0)
    {
        cout << "List is empty";
        return;
    }
    for(int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            array[i] = array[size - 1];
            size--;
            i--;
        }
    }
    return;
}

void ArrayList::print()
{
    if (size == 0)
    {
        cout << "List is empty";
        return;
    }
    for(int i = 0; i < size; i++)
    cout << array[i] << " ";
    return;
}

ArrayList::~ArrayList()
{
    delete[] array;
}
