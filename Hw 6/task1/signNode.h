#pragma once

class SignNode : public TreeNode
{
public:
    SignNode(char c);
    int calculate();
    void prefixPrint();
    void postfixPrint();
};
