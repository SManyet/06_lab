// stacks are last in, first out, like a pringles can
//
// push() = place on top
// pop() = deletes and returns the first item
// peek()/top() = shows top item without removing
// length() = get length of stack
// is_empty()/is_full()
// make_empty()
// get_capacity() = whats left
//
// vvvvv building the stack vvvvv
// imagine array on side, 0 on bottom

class Stack {
    private: 
        const int MAX_SIZE = 5;
        int stack[5];
        int top = 0;

    public:
        void push(const int inVal) {
            if (!isFull()) {
                stack[top] = inVal;
                top++;
            } else {
                throw "StackOverflow";
            }  
        }
        int pop() {
            if (!isEmpty()) {
                top--;
                return stack[top];
            } else {
                throw "StackUnderflow";
            }
        }
        bool isFull() {
            return top == MAX_SIZE;
        }
        bool isEmpty() {
            return top == 0;
        }
        int peak() {
            if (!isEmpty()) {
                return stack[top - 1];
            } else {
                throw "StackUnderflow";
            }
        }
        int length() {
            return top;
        }
        void makeEmpty() {
            top = 0;
        }
};
