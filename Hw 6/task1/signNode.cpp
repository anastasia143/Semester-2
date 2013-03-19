#include <iostream>
#include "treeNode.h"
#include "signNode.h"

SignNode::SignNode(char c)
{
    left = NULL;
    right = NULL;
    value = c;
}

int SignNode::calculate()
{
    switch(value)
    {
    case '+':
    {
        return left->calculate() + right->calculate();
        break;
    }
    case '-':
    {
        return left->calculate() - right->calculate();
        break;
    }
    case '/':
    {
        return left->calculate() / right->calculate();
        break;
    }
    case '*':
    {
        return left->calculate() * right->calculate();
        break;
    }
    }
}

void SignNode::prefixPrint()
{
    std::cout << value << " ";
    left->prefixPrint();
    right->prefixPrint();
}

void SignNode::postfixPrint()
{
    right->prefixPrint();
    left->prefixPrint();
    std::cout << value << " ";
}
