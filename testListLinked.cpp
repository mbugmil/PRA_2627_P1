#include "ListLinked.h"
#include <cassert>
#include <iostream>
#include <stdexcept>
int main() {
    ListLinked<int> list;
    assert(list.empty());
    assert(list.size() == 0);
    list.append(10);
    list.append(30);
    list.prepend(5);
    list.insert(2, 20);
    assert(list.size() == 4);
    assert(list.get(0) == 5);
    assert(list.get(1) == 10);
    assert(list.get(2) == 20);
    assert(list.get(3) == 30);
    assert(list.search(20) == 2);
    assert(list.search(99) == -1);
    assert(list.remove(2) == 20);
    assert(list.remove(0) == 5);
    assert(list.size() == 2);
    assert(list.get(0) == 10);
    assert(list.get(1) == 30);
    bool exception_thrown = false;
    try { list.remove(10); }
    catch (const std::out_of_range&) { exception_thrown = true; }
    assert(exception_thrown);
    std::cout << list << std::endl;
    return 0;
}
