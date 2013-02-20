#include <iostream>
#include "listCommands.h"
#include "list.h"
using namespace std;

void listCommands(List* list)
{
    cout << endl << "What do you want to do with your List?" <<
        endl << "0 - exit"<<
        endl << "1 - add a new value"<<
        endl << "2 - remove the value"<<
        endl << "3 - print the List" << endl;

    int command = 0;
    cout << endl << endl << "Enter command: ";
    cin >> command;
    while (command != 0)
    {
        int value;
        switch (command)
        {
        case 1:
        {
            cout << "Enter new value for adding: ";
            cin >> value;
            list->add(value);
            break;
        }
        case 2:
        {
            cout << "Enter new value for removing: ";
            cin >> value;
            list->remove(value);
            break;
        }
        case 3:
        {
            list->print();
            break;
        }
        }
        cout << endl << endl << "Enter command: ";
        cin >> command;
    }
}
