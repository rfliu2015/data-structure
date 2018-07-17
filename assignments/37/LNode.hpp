#ifndef LNODE_HPP
#define LNODE_HPP

template <typename T>
struct LNode {
    T value;
    struct LNode *next;
};

#endif /* ifndef LNODE_HPP */
