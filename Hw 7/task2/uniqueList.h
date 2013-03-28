#pragma once
#include "list.h"

struct ListElement
{
    int value;
    ListElement *next;
};

/**
@class UniqueList
@brief Pointer List that doesn`t allow to add equal elements.
*/
class UniqueList : public List
{
public:
    UniqueList();
    ~UniqueList();
    void add(int value);
    void remove(int value);
    void print();
    bool check(int value);
    void clear();
private:
    ListElement* head;
};
