#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

//Queue template
template <class T>
class Queue {

    private:
        T *queueArray[100]; //
        int queueSize;
        int front;
        int back;
        int numItems;

    public:
    //constructor
    Queue(int); //
    class StackOverflow;
    class StackUnderflow;

    // Queue operations
    void enqueue(T);
    void dequeue(T &); //TODO: why is this a variable reference?
    bool isEmpty() const;
    bool isFull() const;
    void clear();


};

#endif