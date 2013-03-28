#pragma once

/**
@class List is the interface of different kinds of lists.
@brief In this program there is one realization  - @class UniqueList
*/

class List
{
public:
    virtual void add(int value) = 0;
    virtual void remove(int value) = 0;
    virtual void print() = 0;
    virtual bool check(int value) = 0;
    virtual void clear() = 0;
    int getSize() { return size; }
protected:
    int size;
};
