#pragma once
#include "stack.h"

struct ListElement
{
    char value;
    ListElement *next;
};

class ListStack : public Stack
{
public:
    ListStack();
    ~ListStack();
    void push(char value);
    void pop();
    bool empty();
    char top();
protected:
    ListElement* head;
};
