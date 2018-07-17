struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

class MyLinkedList
{
  private:
    Node *head, *tail;
    int size;

  public:
    /** Initialize your data structure here. */
    MyLinkedList() : head(new Node(-999)), tail(nullptr), size(0) {}

    /** Get the value of the index-th node in the linked list. If the index is
     * invalid, return -1. */
    int get(int index)
    {
        if (index < 0 || index >= size) {
            return -1;
        }

        Node* node = _get(index);
        return node->value;
    }

    /** Add a node of value val before the first element of the linked list.
     * After the insertion, the new node will be the first node of the linked
     * list. */
    void addAtHead(int val)
    {
        Node* node = new Node(val);

        node->next = head->next;
        head->next = node;

        if (size == 0) {
            tail = head->next;
        }

        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Node* node = new Node(val);

        if (size == 0) {
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        tail->next = nullptr;

        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If
     * index equals to the length of linked list, the node will be appended to
     * the end of linked list. If index is greater than the length, the node
     * will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size) {
            /* std::cout << "参数不正确！" << std::endl; */
            return;
        }

        if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else {
            Node* node = new Node(val);

            Node* pre = _get(index - 1);
            node->next = pre->next;
            pre->next = node;

            size++;
        }
    }


    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size) {
            return;
        }

        Node* pre;
        if (index == 0) {
            pre = head;
        } else {
            pre = _get(index - 1);
        }

        Node* todel = pre->next;
        pre->next = todel->next;

        if (todel == tail) {
            tail = pre;
        }
        delete todel;

        size--;
    }

    Node* _get(int index)
    {
        Node* node = head->next;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }

        return node;
    }

    Node* get_head() { return head; }
};
