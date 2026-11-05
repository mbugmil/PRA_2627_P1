#ifndef LIST_LINKED_H
#define LIST_LINKED_H
#include "List.h"
#include "Node.h"
#include <iostream>
#include <stdexcept>
template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;
    Node<T>* nodeAt(int pos) {
        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) current = current->next;
        return current;
    }
public:
    ListLinked() : first(nullptr), n(0) {}
    ~ListLinked() override {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
        n = 0;
    }
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) throw std::out_of_range("insert");
        if (pos == 0) first = new Node<T>(e, first);
        else {
            Node<T>* previous = nodeAt(pos - 1);
            previous->next = new Node<T>(e, previous->next);
        }
        ++n;
    }
    void append(T e) override { insert(n, e); }
    void prepend(T e) override { insert(0, e); }
    T remove(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("remove");
        Node<T>* removed;
        if (pos == 0) {
            removed = first;
            first = first->next;
        } else {
            Node<T>* previous = nodeAt(pos - 1);
            removed = previous->next;
            previous->next = removed->next;
        }
        T value = removed->data;
        delete removed;
        --n;
        return value;
    }
    T get(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("get");
        return nodeAt(pos)->data;
    }
    T operator[](int pos) { return get(pos); }
    int search(T e) override {
        Node<T>* current = first;
        int pos = 0;
        while (current != nullptr) {
            if (current->data == e) return pos;
            current = current->next;
            ++pos;
        }
        return -1;
    }
    bool empty() override { return n == 0; }
    int size() override { return n; }
    friend std::ostream& operator<<(std::ostream& os, const ListLinked<T>& list) {
        os << "[";
        Node<T>* current = list.first;
        while (current != nullptr) {
            os << current->data;
            current = current->next;
            if (current != nullptr) os << ", ";
        }
        os << "]";
        return os;
    }
};
#endif
