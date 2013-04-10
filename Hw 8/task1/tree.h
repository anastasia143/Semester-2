#pragma once
#include <iostream>
#include "treeNode.h"
using namespace std;

/**
@class Bag
@brief This pattern class implements functions of multiset.
You can add equal elements and Bag will count it.
You can remove equal elements and Bag will reduce counter.
*/

template <typename T>
class Bag
{
public:
    Bag() : root(NULL), count(0) {}
    ~Bag();
    void deleteTree(TreeNode<T>* temp);
    void clear();
    int returnCount() { return count; }
/**
Direct functional
*/
    void add(T value);
    void remove(T value);
    bool exist(T value);
    int getElementCount(T value);
    TreeNode<T>* root;
/**
Print functions that use defferent tree traversals
*/
private:
    int count;
    void printAscending();
    void printAscending(TreeNode<T> *node);
    void printDescending();
    void printDescending(TreeNode<T> *node);
/**
Helping recursive functions
*/
    void add(TreeNode<T> *&node, T value);
    void remove(TreeNode<T> *&node, T value);
    bool exist(TreeNode<T>* &node, T value);
    int getElementCount(TreeNode<T> *&node, T value);
};

template <typename T>
void Bag<T>::add(T value)
{
    add(root, value);
    count++;
}

template <typename T>
void Bag<T>::add(TreeNode<T> *&node, T value)
{
    if (node == NULL)
    {
        node = createTreeNode(value);
        return;
    }
    if (value < node->value)
        add(node->left, value);
    else if (value > node->value)
        add(node->right, value);
    else
        node->count++;
}

template <typename T>
void Bag<T>::printAscending()
{
    if (count == 0)
    {
        cout << "Tree is empty";
        return;
    }
    cout << "Value/count" << endl;
    if (count == 1)
    {
        cout << root->value << "/" << root->count << endl;
        return;
    }
    printAscending(root);
}

template <typename T>
void Bag<T>::printAscending(TreeNode<T> *node)
{
    if (node != NULL)
    {
        printAscending(node->left);
        cout << node->value << "/" << node->count << " ";
        printAscending(node->right);
    }
}

template <typename T>
void Bag<T>::printDescending()
{
    if (count == 0)
    {
        cout << "Tree is empty";
        return;
    }
    cout << "Value/count" << endl;
    if (count == 1)
    {
        cout << root->value << "/" << root->count << endl;
        return;
    }
    printDescending(root);
}

template <typename T>
void Bag<T>::printDescending(TreeNode<T> *node)
{
    if (node != NULL)
    {
        printDescending(node->right);
        cout << node->value << "/" << node->count << " ";
        printDescending(node->left);
    }
}

template <typename T>
bool Bag<T>::exist(T value)
{
    if (count == 0)
        return false;
    if (root->value == value)
        return true;
    return exist(root, value);
}

template <typename T>
bool Bag<T>::exist(TreeNode<T> *&node, T value)
{
    if (node == NULL)
        return false;
    if (node->value == value)
        return true;
    if (value < node->value)
        return exist(node->left, value);
    else
        return exist(node->right, value);
}

template <typename T>
int Bag<T>::getElementCount(T value)
{
    if (!exist(value))
        return 0;
    else
        return getElementCount(root, value);
}

template <typename T>
int Bag<T>::getElementCount(TreeNode<T> *&node, T value)
{
    if (node->value == value)
        return node->count;
    if (value < node->value)
        return getElementCount(node->left, value);
    else
        return getElementCount(node->right, value);
}

template <typename T>
void Bag<T>::remove(T value)
{
    if (exist(value))
    {
        count--;
        remove(root, value);
    }
    else
        cout << "There is no this element in the tree." << endl;
}

template <typename T>
void Bag<T>::remove(TreeNode<T> *&node, T value)
{

    if (value < node->value)
    {
        remove(node->left, value);
    }
    else if (value > node->value)
    {
        remove(node->right, value);
    }
    else if (node->count > 1)
    {
        node->count--;
        return;
    }
    else if (hasNoChild(node))
    {
        delete node;
        node = NULL;
        return;
    }
    else if (hasOneChild(node))
    {
        if (node->left != NULL)
        {
            TreeNode<T> *temp = node->left;
            delete node;
            node = temp;
        }
        if (node->right != NULL)
        {
            TreeNode<T> *temp = node->right;
            delete node;
            node = temp;
        }
    }
    else
    {
        TreeNode<T> *temp = leftMostChild(node->right);
        node->value = temp->value;
        node->right = temp->right;

        if (hasNoChild(temp))
        {
            delete temp;
            temp = NULL;
            return;
        }
        else
        {
            TreeNode<T> *pemp = temp->right;
            delete temp;
            temp = pemp;
        }
    }
}

template <typename T>
void Bag<T>::deleteTree(TreeNode<T>* temp)
{
    TreeNode<T> *node = temp;
    if (node != NULL)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

template <typename T>
void Bag<T>::clear()
{
    deleteTree(root);
    root = NULL;
    count = 0;
}

template <typename T>
Bag<T>::~Bag()
{
    deleteTree(root);
}
