/**
*@author Semenova Anastasia
*@version 1.0
*/

// Task is ready for check

#include <iostream>
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "stack.h"
#include "arrayStack.h"
#include "listStack.h"
#include "commands.h"
#include "stackTests.h"
using namespace std;

int main()
{
    StackTests test;
    QTest::qExec(&test);

    // Interactive mode

    /*cout << "What kind of stack do you want to create?" <<
            endl << "1 - List Stack" <<
            endl << "2 - Array Stack" << endl;
    int command;
    cin >> command;

    Stack* stack = stackCreator(command);
    commands(stack);
    delete stack;*/

    return 0;
}
