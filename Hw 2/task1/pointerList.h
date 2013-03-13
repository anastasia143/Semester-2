#pragma once
#include "list.h"

struct ListElement
{
    int value;
    ListElement *next;
};


class PointerList : public List
{
public:
    PointerList();
    ~PointerList();
    void add(int value);
    void remove(int value);
    void print();
    bool check(int value);
protected:
    ListElement* head;
    int size;
};

