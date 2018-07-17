### [Design Linked List](https://leetcode.com/explore/learn/card/linked-list/209/singly-linked-list/1290/)

Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: `val` and `next`. `val` is the value of the current node, and `next` is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute `prev` to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

- `get(index)` : Get the value of the `index`-th node in the linked list. If the index is invalid, return `-1`.
- `addAtHead(val)` : Add a node of value `val` before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
- `addAtTail(val)` : Append a node of value `val` to the last element of the linked list.
- `addAtIndex(index, val)` : Add a node of value `val` before the `index`-th node in the linked list. If `index` equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
- `deleteAtIndex(index)` : Delete the `index`-th node in the linked list, if the index is valid.

##### Example:

```c++
MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
```

##### Note:

- All values will be in the range of `[1, 1000]`.
- The number of operations will be in the range of `[1, 1000]`.
- Please do not use the built-in LinkedList library.

##### 实现：

```c++
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

```

### 几个说明的点：

- 用`Node* _get(int index)`辅助实现。这里`_get()`只要完成最基本的功能就可以了。不要做多余的判断。

- 每个函数都有可能修改私有域的值，比如`addAtTail(int val)`和`addAtIndex(int index, int val)`。因此要检查每个方法对私有域如何修改，比如`head`，`tail`，还有`size`。

- 对上面那点，麻烦的地方在于比如方法`deleteAtIndex(int index)`，显而易见会有`size--`，但是`head`和`tail`会不会发生改变呢？另一个方法`addAtIndex(int index, int val)`又是怎么样呢？

  `head`不会，但是`tail`*可能*会。这里的“可能”是要分情况讨论的！

  尤其注意，分情况讨论对删除的过程没有影响，但是对属性的修改至关重要！ <!--在这里栽过无数坑！-->

### END