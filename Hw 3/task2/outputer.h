#pragma once

class Outputer
{
public:
    void output(int** array, int size);
    virtual void print(int number) = 0;
};
