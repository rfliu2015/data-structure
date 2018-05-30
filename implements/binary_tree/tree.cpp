#include <iostream>
#include "./BinaryTree.hpp"
#include "./BinaryTreeNode.hpp"
using namespace std;

template <typename T>
void printValue(BinaryTreeNode<T> node)
{
    cout << node.value;
}

template <typename T>
void printValue(BinaryTreeNode<T> *pnode)
{
    cout << pnode->value << endl;
}

int main(void)
{
    BinaryTree<int> bt;

    bt.init(10);
    /* printValue(bt.root); */

    std::cout << "先序遍历:" << std::endl;
    bt.preOrder();
    std::cout << std::endl;

    std::cout << "中序遍历:" << std::endl;
    bt.inOrder();
    std::cout << std::endl;

    std::cout << "后序遍历:" << std::endl;
    bt.postOrder();
    std::cout << std::endl;

    std::cout << "层序遍历:" << std::endl;
    bt.bfsOrder();
    std::cout << std::endl;
    return 0;
}
