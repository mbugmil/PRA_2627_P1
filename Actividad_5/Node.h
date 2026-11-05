#ifndef NODE_H
#define NODE_H
#include <iostream>
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}
    friend std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
        os << node.data;
        return os;
    }
};
#endif
