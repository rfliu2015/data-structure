#ifndef BINARYTREE
#define BINARYTREE
#include <queue>
#include <stack>
#include "./BinaryTreeNode.hpp"

template <typename T>
void visitNode(BinaryTreeNode<T>* pn)
{
    std::cout << pn->value << "  ";
}

/**
 * 先序遍历的递归实现
 */
template <typename T>
void _preOrderRecur(BinaryTreeNode<T>* pn)
{
    if (pn == nullptr) {
        return;
    }

    visitNode(pn);
    _preOrderRecur(pn->left);
    _preOrderRecur(pn->right);
}

/**
 * 先序遍历的非递归实现
 */
template <typename T>
void _preOrderNonRecur(BinaryTreeNode<T>* pn)
{
    std::stack<BinaryTreeNode<T>*> stack;

    BinaryTreeNode<T>* p = pn;
    while (p != nullptr || !stack.empty()) {
        while (p != nullptr) {
            visitNode(p);
            stack.push(p);
            p = p->left;
        }

        p = stack.top();
        stack.pop();
        p = p->right;
    }

    std::cout << std::endl;
}

/**
 * 后序遍历的非递归实现
 */
template <typename T>
void _postOrderNonRecur(BinaryTreeNode<T>* root)
{
    BinaryTreeNode<T>* lastVisited = nullptr;
    BinaryTreeNode<T>* p = root;

    std::stack<BinaryTreeNode<T>*> stack;
    while (!stack.empty() || p != nullptr) {
        while (p != nullptr) {  //一直把左链放进堆栈
            stack.push(p);
            p = p->left;
        }

        BinaryTreeNode<T>* peekNode = stack.top();
        if (peekNode->right != nullptr &&
            peekNode->right != lastVisited) {  //可以右移
            p = peekNode->right;  //原本p指向因为不停左移的null
        } else {                  //回退
            visitNode(peekNode);
            lastVisited = peekNode;
            stack.pop();
        }
    }

    std::cout << std::endl;
}

/**
 * 中序遍历的非递归实现
 */
template <typename T>
void _inOrderNonRecur(BinaryTreeNode<T>* root)
{
    std::stack<BinaryTreeNode<T>*> stack;

    BinaryTreeNode<T>* p = root;
    while (p != nullptr || !stack.empty()) {
        while (p != nullptr) {
            stack.push(p);
            p = p->left;
        }

        p = stack.top();
        stack.pop();
        visitNode(p);
        p = p->right;
    }

    std::cout << std::endl;
}

/**
 * 层序遍历
 */
template <typename T>
void _bfsOrder(BinaryTreeNode<T>* root)
{
    std::queue<BinaryTreeNode<T>*> que;
    BinaryTreeNode<T>* p = root;
    que.push(p);
    while (!que.empty()) {
        BinaryTreeNode<T>* q = que.front();
        que.pop();
        visitNode(q);

        if (q->left != nullptr) {
            que.push(q->left);
        }
        if (q->right != nullptr) {
            que.push(q->right);
        }
    }

    std::cout << std::endl;
}

template <typename T>
class BinaryTree
{
  public:
    BinaryTreeNode<T>* root;

  public:
    BinaryTree(T value) { root->value = value; }
    BinaryTree() {}
    void preOrder() { _preOrderNonRecur(root); }
    void inOrder() { _inOrderNonRecur(root); }
    void postOrder() { _postOrderNonRecur(root); }
    void bfsOrder() { _bfsOrder(root); }
    void init(T i)
    {
        root = new BinaryTreeNode<T>(i);
        root->left = new BinaryTreeNode<T>(1);
        root->left->left = new BinaryTreeNode<T>(3);
        root->left->left->right = nullptr;
        root->left->left->left = nullptr;
        root->left->right = new BinaryTreeNode<T>(4);
        root->left->right->left = new BinaryTreeNode<T>(5);
        root->left->right->right = nullptr;

        root->right = new BinaryTreeNode<T>(2);
        root->right->left = new BinaryTreeNode<T>(6);
        root->right->left->left = nullptr;
        root->right->left->right = nullptr;
        root->right->right = new BinaryTreeNode<T>(7);
        root->right->right->left = new BinaryTreeNode<T>(8);
        root->right->right->right = nullptr;
    }

    virtual ~BinaryTree(){};

  private:
    /* data */
};

#endif /* ifndef BINARY */
