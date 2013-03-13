#pragma once
#include "list.h"

class ArrayList : public List
{
public:
    ArrayList();
    ~ArrayList();
    void add(int value);
    void remove(int value);
    void print();
    bool check(int value);
protected:
    int* array;
    int size;
};
