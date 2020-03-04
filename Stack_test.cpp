#ifndef STACK_H
#define STACK_H
#include <iostream>


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
                stack[head] = item;
                std::cout << head << ": "<< stack[head] << std::endl;
                head++;
            }  
        }
        T* pop() {
            if (stack[0] == nullptr) {
                throw StackUnderflow();
            } 
            head--;
            T *temp = stack[head];
            std::cout << head << " head is "<< *stack[head] << std::endl;
            std::cout << "temp is "<< temp << std::endl;
            return temp;
        }
        T* top() {
            return stack[head];
        }
        int length() {
            int i = 0;
            while (stack[i] != nullptr) {
                i++;
            }
            return i;
        }
        // void empty();
};
#endif
