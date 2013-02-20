#include <iostream>
#include "pointerList.h"
#include "arrayList.h"
#include "listCommands.h"
using namespace std;

int main()
{
    cout << "What kind of List do you want to create?" <<
            endl << "1 - List on the array" << endl << "2 - List on the pointers" << endl;
    unsigned int command = 0;
    cin >> command;
    if (command == 1)
    {
        List *list = new ArrayList();
        cout << "You have created new List on the array";
        listCommands(list);
        delete list;
    }
    else
    {
        List *list = new PointerList();
        cout << "You have created new List on pointers";
        listCommands(list);
        delete list;
    }
    return 0;
}
