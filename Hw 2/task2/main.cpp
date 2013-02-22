#include <iostream>
#include "stack.h"
#include "arrayStack.h"
#include "listStack.h"
#include "commands.h"
using namespace std;

int main()
{
    cout << "What kind of stack do you want to create?" <<
            endl << "1 - List Stack" <<
            endl << "2 - Array Stack" << endl;
    int command;
    cin >> command;

    if (command == 1)
    {
        Stack* stack = new ListStack();
        commands(stack);
        delete stack;
    }
    else
    {
        Stack* stack = new ArrayStack();
        commands(stack);
        delete stack;
    }
    
    return 0;
}
