#pragma once

/**
@class TreeNode
@brief This class has two heritors: digits and signs.
It helps to return different values when you call function calculate()
and to print different values when you call function print().
*/
class TreeNode
{
public:
    void print();
    virtual int calculate() = 0;
    virtual void prefixPrint() = 0;
    virtual void postfixPrint() = 0;
    char value;
    TreeNode *left;
    TreeNode *right;
};
