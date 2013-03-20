#pragma once

template <typename T>
struct TreeNode
{
    T value;
    TreeNode *left;
    TreeNode *right;
};

template <typename T>
TreeNode<T>* createTreeNode(T element)
{
    TreeNode<T> *node = new TreeNode<T>;
    node->left = NULL;
    node->right = NULL;
    node->value = element;
    return node;
}

// These functions are used in removing value from tree,
// but are not part of direct tree functional.
template <typename T>
TreeNode<T> *leftMostChild(TreeNode<T> *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

template <typename T>
bool hasNoChild(TreeNode<T> *node)
{
    return (node->left == NULL) && (node->right == NULL);
}

template <typename T>
bool hasOneChild(TreeNode<T> *node)
{
    return ((node->left == NULL) && (node->right != NULL)) ||
            ((node->left != NULL) && (node->right == NULL));
}
