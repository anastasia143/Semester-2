#include "calculator.h"
#include "counter.h"

Counter::Counter()
{
    isItArg1 = true;
}

void Counter::addSign(int sign)
{
    operation = sign;
    isItArg1 = false;
    return;
}

QString Counter::addNumber(int number)
{
    if (isItArg1)
    {
        arg1.append(QString::number(number));
        return arg1;
    }
    else
    {
        arg2.append(QString::number(number));
        return arg2;
    }

}

QString Counter::addPoint()
{
    if (isItArg1)
    {
        arg1.append('.');
        return arg1;
    }
    else
    {
        arg2.append('.');
        return arg2;
    }
}

QString Counter::calculate()
{
    isItArg1 = true;
    double result = 0;
    double firstNumber = arg1.toDouble();
    double secondNumber = arg2.toDouble();

    arg1.clear();
    arg2.clear();

    switch(operation)
    {
    case 0:
        result = firstNumber + secondNumber;
        break;
    case 1:
        result = firstNumber - secondNumber;
        break;
    case 2:
        result = firstNumber * secondNumber;
        break;
    case 3:
    {
        if (secondNumber == 0)
        {
            return "error";
        }
        result = firstNumber / secondNumber;
        break;
    }
    }
    return (QString::number(result));
}
