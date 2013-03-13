#pragma once

class Stack
{
public:
    virtual void push(char value) = 0;
    virtual void pop() = 0;
    virtual bool empty() = 0;
    virtual char top() = 0;
protected:
    int size;
};

Stack* stackCreator(int number);
