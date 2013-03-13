#include "stack.h"
#include "listStack.h"
#include "arrayStack.h"


Stack* stackCreator(int number)
{
    switch(number)
    {
    case 1:
    {
        Stack* stack = new ListStack();
        return stack;
        break;
    }
    default:
    {
        Stack* stack = new ArrayStack();
        return stack;
        break;
    }
    }
}
