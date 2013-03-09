#pragma once
#include "calculator.h"

class Counter
{
public:
    Counter();
    QString addNumber(int number);
    void addSign(int sign);
    QString calculate();
    QString addPoint();
    void clearCounter();

private:
    int operation;
    QString arg1;
    QString arg2;
    bool isItArg1;
};
