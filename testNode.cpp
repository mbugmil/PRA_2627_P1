#include "Node.h"
#include <cassert>
#include <iostream>
int main() {
    Node<int> node3(30);
    Node<int> node2(20, &node3);
    Node<int> node1(10, &node2);
    assert(node1.data == 10);
    assert(node1.next == &node2);
    assert(node2.data == 20);
    assert(node2.next == &node3);
    assert(node3.data == 30);
    assert(node3.next == nullptr);
    std::cout << node1 << std::endl;
    return 0;
}
