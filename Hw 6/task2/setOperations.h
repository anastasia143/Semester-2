#pragma once
#include "tree.h"

/**
Intersection two sets: function creates new tree that has nodes of both tree1 and tree 2 at the same time
*/
template <typename T>
Tree<T>* intersection(Tree<T>* &tree1, Tree<T>* &tree2)
{
    Tree<T>* interTree = new Tree<T>();
    intersection(tree1->root, tree2, interTree);
    return interTree;
}

template <typename T>
void intersection(TreeNode<T>* &node, Tree<T>* &tree2, Tree<T>* &interTree)
{
    if (node != NULL)
    {
        if (tree2->exist(node->value))
            interTree->add(node->value);
        intersection(node->left, tree2, interTree);
        intersection(node->right, tree2, interTree);
    }
}

/**
Merger two sets: function creates new tree that has nodes existing at least in one tree
*/
template <typename T>
Tree<T>* merger(Tree<T>* &tree1, Tree<T>* &tree2)
{
    Tree<T>* mergerTree = new Tree<T>();
    merger(tree1->root, mergerTree);
    merger(tree2->root, mergerTree);
    return mergerTree;
}

template <typename T>
void merger(TreeNode<T>* &node, Tree<T>* &mergerTree)
{
    if (node != NULL)
    {
        mergerTree->add(node->value);
        merger(node->left, mergerTree);
        merger(node->right, mergerTree);
    }
}
