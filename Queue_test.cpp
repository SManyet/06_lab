#ifndef QUEUETEST_H
#define QUEUETEST_H

template <class T>
class Queue {
    private:
        T **queueArray;
        int queueSize;
        int front;
        int back;
        int numItems;
    public:
        Queue(int size) {
            queueArray = new T*[size];
            queueSize = size;
            front = -1;
            back = -1;
            numItems = 0;
        }

        class StackUnderflow{};
        class StackOverflow{};

        void enqueue(T *item) {
            if (isFull())
                throw StackOverflow();
            else {
                back = (back + 1) % queueSize;
                queueArray[back] = item;
                numItems++;
            }
        }

        T* dequeue() {
            if (isEmpty()) {
                throw StackUnderflow();
            }
            front = (front + 1) % queueSize;
            T *temp = queueArray[front];
            numItems--;
            return temp;
        }



        bool isEmpty() {
            return (numItems == 0);
        }

        bool isFull() {
            return (numItems >= queueSize);
        }

        void clear() {
            front = queueSize - 1;
            back = queueSize - 1;
            numItems = 0;
        }
        
        int getNumItems() {
            return numItems;
        }
};
#endif
