#pragma once
#include <iostream>
using namespace std;

class Removable
{
public:
    Removable()
    {
        cout << "Object was created." << endl;
    }
    ~Removable()
    {
        cout << "Object was deleted." << endl;
    }
};

class Thrower
{
public:
    Thrower()
    {
        throw exception;
    }

private:
    Removable removable;
    static int const exception = 1;
};

