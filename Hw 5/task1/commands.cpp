#include <iostream>
#include "commands.h"
using namespace std;

void interactive(HashTable* table)
{
    cout << "You have commands: "
         << endl << "0 - exit"
         << endl << "1 - add value"
         << endl << "2 - remove value"
         << endl << "3 - check availability value in the table"
         << endl << "4 - show statistics";

    cout << endl << endl;
    cout << "Please, choose hashKey function: "
         << endl << "1 - using length of string"
         << endl << "2 - using polynomial from char codes" << endl;
    int command  = 9;
    cin >> command;
    HashKeyFunctions* hashKeyFunction = hashKeyFunctionsCreator(command);

    cout << endl << "Enter command: ";
    cin >> command;

    char* str = new char[100];
    clear(str);

    while(command != 0)
    {
        switch(command)
        {
        case 1:
        {
            cout << "Enter string for adding: ";
            cin >> str;
            table->addValue(str, hashKeyFunction);
            break;
        }
        case 2:
        {
            cout << "Enter string for removing: ";
            cin >> str;
            table->removeValue(str, hashKeyFunction);
            break;
        }
        case 3:
        {
            cout << "Enter string for checking: ";
            cin >> str;
            if (table->checkAvailability(str, hashKeyFunction))
                cout << "True.";
            else
                cout << "False.";
            cout << endl;
            break;
        }
        case 4:
        {
            table->showStatistics();
            break;
        }
        default:
        {
            command = 0;
            break;
        }
        }

        cout << endl << "Enter command: ";
        cin >> command;
        clear(str);
    }

}

void clear(char* str)
{
    for(int i = 0; i < 100; i++)
        str[i] = '\n';
}
