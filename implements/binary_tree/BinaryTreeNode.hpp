#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
public:
    BinaryTreeNode(T value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
    void setValue(T value)
    {
        this->value = value;
    }
};

#endif /* ifndef BINARYTREENODE_H */
