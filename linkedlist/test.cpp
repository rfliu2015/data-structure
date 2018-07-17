#include <iostream>
#include "./MyLinkedList.h"

using namespace std;

void print(Node* head)
{
    if (head == nullptr) return;
    Node* node = head->next;
    while (node != nullptr) {
        cout << node->value << "  ";
        node = node->next;
    }
    cout << endl;
}

int main(void)
{
    MyLinkedList* lk = new MyLinkedList();
    lk->addAtHead(8);
    std::cout << lk->get(1) << std::endl;
    lk->addAtTail(81);
    lk->deleteAtIndex(2);
    lk->addAtHead(26);
    lk->deleteAtIndex(2);
    std::cout << lk->get(1) << std::endl;
    lk->addAtHead(25);
    lk->addAtTail(0);
    lk->addAtTail(13);
    lk->addAtTail(1);
    lk->addAtIndex(6, 33);

    print(lk->get_head());
    lk->addAtTail(24);
    print(lk->get_head());
    return 0;
}
