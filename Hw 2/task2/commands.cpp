#include <iostream>
#include "stack.h"
#include "commands.h"
#include "calculator.h"
using namespace std;

void commands(Stack* stack)
{
    cout << endl << "What do you want to do with your stack?" <<
            endl << "0 - exit" <<
            endl << "1 - push (add new value)" <<
            endl << "2 - pop (remove the last value)"<<
            endl << "3 - top (get the last value)" <<
            endl << "4 - check the stack of emptiness" <<
            endl << "5 - calculate the expression" <<
            endl << "(Attention! If you enter the 5th command, all elements in stack will be removed)" << endl << endl;

    int command = 8;
    cout << "Enter command: ";
    cin >> command;
    while (command != 0)
    {
        switch(command)
        {
        case 1:
        {
            char value = '\n';
            cout << "Enter value for adding: ";
            cin >> value;
            stack->push(value);
            break;
        }
        case 2:
        {
            stack->pop();
            break;
        }
        case 3:
        {
            if (stack->empty())
                cout << "Stack is empty";
            else
                cout << "The last element in stack: " << stack->top();
            break;
        }
        case 4:
        {
            if (stack->empty())
                cout << "Stack is empty";
            else
                cout << "There are elements in stack";
            break;
        }
        case 5:
        {
            char* str = new char[1000];
            for(int i = 0; i < 1000; i++)
                str[i] = '\n';
            cout << "Enter infix form: ";
            cin >> str;
            cout << endl << "Result: " << calculator(stack, str);
            break;
        }
        default:
        {
            command = 0;
            break;
        }
        }

        cout << endl << endl <<  "Enter command: ";
        cin >> command;
    }
}
