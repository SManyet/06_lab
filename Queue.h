#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

//Queue template
template <class T>
class Queue {

    private:
        T *queueArray;
        int queueSize;
        int front;
        int back;
        int numItems;

    public:
    //constructor
    Queue(int); //
    class StackOverflow{};
    class StackUnderflow{};

    // Queue operations
    void enqueue(T);
    T dequeue(); //TODO: why is this a variable reference?
    bool isEmpty() const;
    bool isFull() const;
    void clear();


};

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
T Queue<T>::dequeue() { 
    if (isEmpty())
        throw StackUnderflow();
    }
    front = (front + 1) % queueSize;
    T temp = queueArray[front];
    numItems--;
    return temp;
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


#endif
