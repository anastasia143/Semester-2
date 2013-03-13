#include <iostream>
#include <string.h>
#include "calculator.h"
using namespace std;

int symbolCode(char ch1)
{
    return ((int)ch1 - '0');
}

int calculate(Stack* stack, char* str)
{
    while(!stack->empty())
        stack->pop();

    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        if (isdigit(str[i]))
            stack->push(str[i]);
        else
        {
            switch(str[i])
            {
            case '+':
            {
                char ch1 = stack->top();
                stack->pop();
                char ch2 = stack->top();
                stack->pop();
                stack->push((char)(symbolCode(ch1) + symbolCode(ch2) + '0'));
                break;
            }
            case '-':
            {
                char ch1 = stack->top();
                stack->pop();
                char ch2 = stack->top();
                stack->pop();
                stack->push((char)(symbolCode(ch2) - symbolCode(ch1) + '0'));
                break;
            }
            case '*':
            {
                char ch1 = stack->top();
                stack->pop();
                char ch2 = stack->top();
                stack->pop();
                stack->push((char)(symbolCode(ch1) * symbolCode(ch2) + '0'));
                break;
            }
            case '/':
            {
                char ch1 = stack->top();
                stack->pop();
                char ch2 = stack->top();
                stack->pop();
                stack->push((char)(symbolCode(ch2) / symbolCode(ch1) + '0'));
                break;
            }
            }
        }
    }
    return ((int)stack->top() - '0');
}

// In comments: there are operators for output postfix form. It doesn't need in tests.

int calculator(Stack* stack, char* str)
{
    //cout << "Postfix: ";

    int postfixCount = -1;
    int len = strlen(str);
    char* postfix = new char[len];
    for(int i = 0; i < len; i++)
        postfix[i] = '\n';
    for (int i = 0; i < len; i++)
    {
        switch(str[i])
        {
        case ')':
            {
                while (!(stack->top() == '(')) // pop before ( and pop (
                {
                    char ch = stack->top();
                    //cout << ch;
                    postfixCount++;
                    postfix[postfixCount] = ch;
                    stack->pop();
                }
                stack->pop();
                break;
            }
        case '(':
            {
                stack->push(str[i]); // push (
                break;
            }
        case '*':
        case '/':
            {
                if (stack->empty()) // if stack is empty - push sign
                {
                    stack->push(str[i]);
                }
                else if ((stack->top() == '+') || (stack->top() == '-') || (stack->top() == '('))
                {
                    stack->push(str[i]);// if in stack operations with small priority - push sign
                }
                else
                {
                    while((stack->top() == '*') || (stack->top() == '/')) // pop operations with equal priority
                    {
                        char ch = stack->top();
                        //cout << ch;
                        postfixCount++;
                        postfix[postfixCount] = ch;
                        stack->pop();
                        if (stack->empty())
                        {
                            break;
                        }
                    }
                    stack->push(str[i]);
                }
                break;
            }
        case '+':
        case '-':
            {
                if (stack->empty()) // if stack is empty - push sign
                {
                    stack->push(str[i]);
                }
                else if (stack->top() == '(')
                {
                    stack->push(str[i]); // if in stack small priority - push sign
                }
                else
                {
                    while((stack->top() == '+') || (stack->top() == '-') ||(stack->top() == '*') || (stack->top() == '/'))
                    {
                        char ch = stack->top(); // pop operations with big or equal priority
                        //cout << ch;
                        postfixCount++;
                        postfix[postfixCount] = ch;
                        stack->pop();
                        if (stack->empty())
                        {
                            break;
                        }
                    }
                    stack->push(str[i]);
                }
                break;

            }
        default:
        {
            //cout << str[i]; // numbers
            postfixCount++;
            postfix[postfixCount] = str[i];
            break;
        }
        }
    }
    while (!stack->empty())
    {
        char ch = stack->top();
        //cout << ch;
        postfixCount++;
        postfix[postfixCount] = ch;
        stack->pop();
    }

    int result = calculate(stack, postfix);
    delete[] postfix;
    return result;
}
