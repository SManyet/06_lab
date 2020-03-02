#include <iostream>
#include "Queue.h"
using namespace std;

template <class T>
Queue<T>::Queue(int size) {
    queueArray = new T[size];
    queueSize = size;
    front = -1;
    back = -1;
    numItems = 0;
}

template <class T>
void Queue<T>::enqueue(T item) {
    if (isFull())
        throw StackOverflow();
    else {
        back = (back + 1) % queueSize;
        queueArray[back] = item;
        numItems++;
    }
}

template <class T>
void Queue<T>::dequeue(T &item) { //TODO: why is this a variable reference?
    if (isEmpty())
        throw StackUnderflow();
    else {
        front = (front + 1) % queueSize;
        item = queueArray[front];
        numItems--;
    }
}

template <class T>
bool Queue<T>::isEmpty() const {
    bool status;

    if(numItems == 0)
        status = false;
    else
        status = true;

    return status;
}

template <class T>
bool Queue<T>::isFull() const {
    bool status;

    if (numItems < queueSize)
        status = false;
    else status = true;

    return status;
}

template <class T>
void Queue<T>::clear() {
    front = queueSize - 1;
    back = queueSize - 1;
    numItems = 0;
}

