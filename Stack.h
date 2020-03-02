#ifndef STACK_H
#define STACK_H


template <class T>
class Stack {
    private: 
        int size;
        T *stack[100];


    public:
        // Stack();
        Stack(int);

        void push(const T*); 
        T* pop();
        T* top();
        int length();
        void empty();

        class StackOverflow;
        class StackUnderflow;
};
#endif
