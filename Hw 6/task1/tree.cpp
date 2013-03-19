#include <iostream>
#include "tree.h"
using namespace std;

Tree::Tree()
{
    root = NULL;
}

void Tree::collectingTree(FILE *file)
{
    collectingTree(file, root);
}

void Tree::collectingTree(FILE* file, TreeNode *&node)
{
    char c;
    if (feof(file))
        return;
    c = fgetc(file);

    while (((c == '(') || (c == ')')) && (!feof(file)))
            c = fgetc(file);

    if ((c == '*') || (c == '/') || (c == '+') || (c == '-'))
    {
        node = new SignNode(c);
        collectingTree(file, node->left);
        collectingTree(file, node->right);
    }
    else
    {
        node = new DigitNode(c);
    }
}

void Tree::printPrefixTree()
{
    root->prefixPrint();
}

void Tree::printPostfixTree()
{
    root->postfixPrint();
}

int Tree::calculate()
{
    return root->calculate();
}

void Tree::deleteTree(TreeNode* temp)
{
    TreeNode *node = temp;
    if (node != NULL)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void Tree::clear()
{
    deleteTree(root);
}

Tree::~Tree()
{
    deleteTree(root);
}
