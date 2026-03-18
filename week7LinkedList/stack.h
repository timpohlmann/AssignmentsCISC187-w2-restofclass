#ifndef STACK_H
#define STACK_H

struct Node {
    int data;//holds the value
    Node* next;//points to the next node which is also a struct
};

class Stack {
private:
    Node* top;//points to a node which we will make the 'top' or left most side of our stack
public:
    Stack();
    void push(int value);
    void pop();
    int peek();
    bool isEmpty();
    void display();
};

#endif
