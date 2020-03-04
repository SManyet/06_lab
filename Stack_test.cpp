#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template <class T>
class Stack {
    private: 
        int size;
        int head = -1;
        T *stack[1000];


    public:
        Stack();
        Stack(int s) {
            size = 1000;
            //stack = new T*[s];
        }
        
        class StackOverflow{};
        class StackUnderflow{};


        void push(T *item) {
            if (head >= size) {
                throw StackOverflow();
            } else {
                head++;
                stack[head] = item;
            }  
        }
        T* pop() {
            if (head == -1) {
                throw StackUnderflow();
            }
            T *temp = stack[head];
            head--;
            return temp;
        }
        T* top() {
            return stack[head];
        }
        int length() {
            return head + 1;
        }
        // void empty();
};
#endif
