#include <iostream>
#include "arrayStack.h"
#include "stack.h"
#include "stdlib.h"
using namespace std;

ArrayStack::ArrayStack()
{
    array = new char[1000];
    for(int i = 0; i < 1000; i++)
        array[i] = '\n';
    size = 0;
}

ArrayStack::~ArrayStack()
{
    delete[] array;
}

void ArrayStack::push(char value)
{
    array[size] = value;
    size++;
}

void ArrayStack::pop()
{
    if (size == 0)
    {
        cout << "Stack is empty";
        return;
    }
    size--;
    array[size] = NULL;
}

bool ArrayStack::empty()
{
    if (size == 0)
        return true;
    else
        return false;
}

char ArrayStack::top()
{
    return array[size - 1];
}
