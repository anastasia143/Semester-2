#include <iostream>
#include "treeNode.h"
#include "digitNode.h"

DigitNode::DigitNode(char c)
{
    left = NULL;
    right = NULL;
    value = c;
}

int DigitNode::calculate()
{
    return (int)value - '0';
}

void DigitNode::prefixPrint()
{
    std::cout << value << " ";
}

void DigitNode::postfixPrint()
{
    std::cout << value << " ";
}
