#ifndef LNODE_HPP
#define LNODE_HPP

typedef struct LNode {
    int value;
    struct LNode *next;
} LNode, *LinkedList;
#endif /* ifndef LNODE_HPP */
