#pragma once

class DigitNode : public TreeNode
{
public:
    DigitNode(char c);
    int calculate();
    void prefixPrint();
    void postfixPrint();
};
