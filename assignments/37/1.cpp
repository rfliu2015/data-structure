#include <iostream>
#include "./LinkedList.hpp"
using namespace std;

void setValue(LinkedList<int> &lt)
{
    push_back(lt, 7);
    push_back(lt, 3);
    push_back(lt, 2);
    push_back(lt, 1);
    push_back(lt, 5);
    push_back(lt, 4);
    push_back(lt, 5);
    push_back(lt, 7);
    push_back(lt, 5);
}

template <typename T>
void delValue(LinkedList<T> &lt, T value)
{
    LNode<T> *pn = lt;
}

int main(void)
{
    LinkedList<int> lt;
    lt = createLinkedList(5);
    setValue(lt);

    std::cout << "开始遍历:" << std::endl;
    printLinedList(lt);
    std::cout << std::endl;

    std::cout << "删除节点值为7:" << std::endl;
    int x = 7;
    delValue(lt, x);
    std::cout << "开始遍历:" << std::endl;
    printLinedList(lt);
    std::cout << std::endl;
    return 0;
}
