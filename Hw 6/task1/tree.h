#pragma once
#include <iostream>
#include "stdio.h"
#include "treeNode.h"
#include "signNode.h"
#include "digitNode.h"

/**
@class Tree
@brief Binary Tree for counting an expression
*/
class Tree
{
public:
    Tree();
    ~Tree();
    void clear();
/** Before the actual calculation we need to build a binary tree on expression */
    void collectingTree(FILE* file);
/** Print functions that use different diversions of the tree */
    void printPrefixTree();
    void printPostfixTree();
/** Actual calculation */
    int calculate();

private:
    TreeNode* root;
/** Helping functions */
    void collectingTree(FILE* file, TreeNode *&node);
    void deleteTree(TreeNode* temp);
};
