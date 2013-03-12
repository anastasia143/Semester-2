#pragma once

struct ListElement
{
    char* value;
    ListElement *next;
};

class PointerList
{
public:
    PointerList();
    ~PointerList();
    void add(char* str);
    void remove(char* str);
    void print();
    bool checkAvailability(char* str);
    int size;
public:
    ListElement* head;
};

bool twoStringsComparison(char* str1, char* str2);
