#include "Queue.h"

int main() {
    Queue<int*> q(30);
    int *first = new int(5);
    q.enqueue(first);
    int *returned = q.dequeue();
    std::cout << returned << endl;

    return 0;
}
