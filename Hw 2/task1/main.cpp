/**
*@author Semenova Anastasia
*@version 1.0
*/

// Task is ready for check

#include <iostream>
#include "pointerList.h"
#include "arrayList.h"
#include "listCommands.h"
#include "listTests.h"
using namespace std;

int main()
{
    ListTests test;
        QTest::qExec(&test);

    // Interactive mode

    /*cout << "What kind of List do you want to create?" <<
            endl << "1 - List on the array" << endl << "2 - List on the pointers" << endl;
    int command = 0;
    cin >> command;
    List* list = listCreator(command);
    cout << "You have created new List.";
    listCommands(list);
    delete list;*/

    return 0;
}
