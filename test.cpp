#include "Queue.h"

int main() {
    Queue<int*> q(30);
    int first = 5;
    int *p= &first;
    q.enqueue(&first);
    int *returned = q.dequeue();
    std::cout << returned << endl;

    return 0;
}
