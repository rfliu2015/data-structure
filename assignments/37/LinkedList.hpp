#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "./LNode.hpp"

// c++的独特写法
template <typename T>
using LinkedList = LNode<T> *;

template <typename T>
LinkedList<T> createLinkedList(T value)
{
    LinkedList<T> head = new LNode<T>();
    LNode<T> *lt = new LNode<T>();
    lt->value = value;
    lt->next = nullptr;
    head->next = lt;

    return head;
}

template <typename T>
void push_back(LinkedList<T> &lt, T value)
{
    LNode<T> *pnode = new LNode<T>();
    pnode->value = value;
    pnode->next = lt->next;
    lt->next = pnode;
}

template <typename T>
void printLinedList(LinkedList<T> &lt)
{
    LNode<T> *pnode = lt->next;
    while (pnode != nullptr) {
        std::cout << pnode->value << "  ";
        pnode = pnode->next;
    }
    std::cout << std::endl;
}
#endif
