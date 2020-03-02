#include "Stack.h"

template <class T>
Stack<T>::Stack(int s) {
    size = s;
}

template <class T>
void Stack<T>::push(const T*) {
    
}

template <class T>
T* Stack<T>::pop() {
    T *temp = top();
}

template <class T>
T* Stack<T>::top() {
    return stack[length() - 1];
}

template <class T>
int Stack<T>::length() {
    int i = 0;
    while (stack[i] != nullptr) {
        i++;
    }
    return i;
}

// class Stack {
//     private: 
//         const int MAX_SIZE = 5;
//         int stack[5];
//         int top = 0;
// 
//     public:
//         void push(const int inVal) {
//             if (!isFull()) {
//                 stack[top] = inVal;
//                 top++;
//             } else {
//                 throw "StackOverflow";
//             }  
//         }
//         int pop() {
//             if (!isEmpty()) {
//                 top--;
//                 return stack[top];
//             } else {
//                 throw "StackUnderflow";
//             }
//         }
//         bool isFull() {
//             return top == MAX_SIZE;
//         }
//         bool isEmpty() {
//             return top == 0;
//         }
//         int peak() {
//             if (!isEmpty()) {
//                 return stack[top - 1];
//             } else {
//                 throw "StackUnderflow";
//             }
//         }
//         int length() {
//             return top;
//         }
//         void makeEmpty() {
//             top = 0;
//         }
// };
