#include "Queue_test.cpp"

#include <iostream>

int main() {
    Queue<int> q(30);
    int first = 5;
    q.enqueue(first);
    int *returned = q.dequeue();
    std::cout << *returned << std::endl;

    return 0;
}
