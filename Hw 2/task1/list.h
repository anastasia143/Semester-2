#pragma once

class List
{
public:
    virtual void add(int value) = 0;
    virtual void remove(int value) = 0;
    virtual void print() = 0;
    virtual bool check(int value) = 0;
};

List* listCreator(int number);
