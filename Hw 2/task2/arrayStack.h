#pragma once
#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack();
    ~ArrayStack();
    void push(char value);
    void pop();
    bool empty();
    char top();
protected:
    char* array;
};
