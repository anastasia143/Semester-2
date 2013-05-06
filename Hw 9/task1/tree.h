#pragma once
#include <iostream>
#include <qlist.h>
#include "treeNode.h"
using namespace std;

/** @class Tree
This class helps to work with "Bag"
*/

template <typename T>
class Tree
{
public:
    Tree() : root(NULL), count(0) {}
    ~Tree();

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
protected:
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

/**
@class Bag
@brief This pattern class implements functions of multiset.
You can add equal elements and Bag will count it.
You can remove equal elements and Bag will reduce counter.
*/
template <typename T>
class Bag : public Tree<T>
{
public:
    class Iterator;
};

/** @class Iterator
Iterator for traversal the class Bag
*/
template <typename T>
class Bag<T>::Iterator
{
public:
    Iterator(Bag<T> *tree)
    {
        iteratorTree = tree;
        bypassedElementsCount = 0;
        bypassedCurrentElementCount = 0;
        currentElement = iteratorTree->root;
        way.append(iteratorTree->root);
        mostLeftChild();
    }
    ~Iterator()
    {
       delete currentElement;
    }

    int next()
    {
        if(!hasNext())
        {
            cout << "Iterator has pushed all elements.";
            return 0;
        }
        else if(bypassedCurrentElementCount < currentElement->count)
        {
            bypassedCurrentElementCount++;
            bypassedElementsCount++;
            return currentElement->value;
        }
        else
        {
            getNextValue(currentElement->value);
            bypassedCurrentElementCount = 1;
            return currentElement->value;
        }
    }

    bool hasNext()
    {
        return(iteratorTree->count != bypassedElementsCount);
    }

    void mostLeftChild()
    {
        while (currentElement->left != NULL)
        {
            currentElement = currentElement->left;
            way.append(currentElement);
        }
    }

    void getNextValue(T currentValue)
    {
        if((currentElement->value > currentValue) || (bypassedElementsCount == 0))
        {
            bypassedElementsCount++;
            return;
        }

        if(currentElement->right != NULL && currentElement->right->value > currentValue)
        {
            currentElement = currentElement->right;
            way.append(currentElement);
            mostLeftChild();
            getNextValue(currentValue);
        }
        else
        {
            way.removeLast();
            currentElement = way.last();
            getNextValue(currentValue);
        }
    }

    void add(int value)
    {
        iteratorTree->add(value);
        if(value < currentElement->value)
            bypassedElementsCount++;
        else if(value == currentElement->value)
            bypassedCurrentElementCount++;
    }

    int remove()
    {
        TreeNode<T>* elementForRemoval = currentElement;
        int result = next();

        iteratorTree->remove(elementForRemoval->value);
        bypassedElementsCount--;
        if(elementForRemoval->value == currentElement->value)
            bypassedCurrentElementCount--;
        else
        {
            way.removeOne(elementForRemoval);
            bypassedCurrentElementCount = 1;
        }
        return result;
    }

private:
    Bag<T>* iteratorTree;
    TreeNode<T>* currentElement;
    int bypassedElementsCount;
    int bypassedCurrentElementCount;
    QList<TreeNode<T>*> way;
};

template <typename T>
void Tree<T>::add(T value)
{
    add(root, value);
    count++;
}

template <typename T>
void Tree<T>::add(TreeNode<T> *&node, T value)
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
void Tree<T>::printAscending()
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
void Tree<T>::printAscending(TreeNode<T> *node)
{
    if (node != NULL)
    {
        printAscending(node->left);
        cout << node->value << "/" << node->count << " ";
        printAscending(node->right);
    }
}

template <typename T>
void Tree<T>::printDescending()
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
void Tree<T>::printDescending(TreeNode<T> *node)
{
    if (node != NULL)
    {
        printDescending(node->right);
        cout << node->value << "/" << node->count << " ";
        printDescending(node->left);
    }
}

template <typename T>
bool Tree<T>::exist(T value)
{
    if (count == 0)
        return false;
    if (root->value == value)
        return true;
    return exist(root, value);
}

template <typename T>
bool Tree<T>::exist(TreeNode<T> *&node, T value)
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
int Tree<T>::getElementCount(T value)
{
    if (!exist(value))
        return 0;
    else
        return getElementCount(root, value);
}

template <typename T>
int Tree<T>::getElementCount(TreeNode<T> *&node, T value)
{
    if (node->value == value)
        return node->count;
    if (value < node->value)
        return getElementCount(node->left, value);
    else
        return getElementCount(node->right, value);
}

template <typename T>
void Tree<T>::remove(T value)
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
void Tree<T>::remove(TreeNode<T> *&node, T value)
{

    if (value < node->value)
        remove(node->left, value);
    else if (value > node->value)
        remove(node->right, value);
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
void Tree<T>::deleteTree(TreeNode<T>* temp)
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
void Tree<T>::clear()
{
    deleteTree(root);
    root = NULL;
    count = 0;
}

template <typename T>
Tree<T>::~Tree()
{
    deleteTree(root);
}
