#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack()
{ // Part 3: initialize stack as empty
    top=nullptr;
}

void Stack::push(int value)
{// Part 4: create new node, set its next to top, update top

    Node* newNode = new Node;  // allocates memory, address determined here
    newNode->data = value;     // stores the 10 (or whatever value)
    newNode->next = top;       // points to old top
    top = newNode;             // new node becomes the new top

}

void Stack::pop()
   { // Part 5: check if empty, remove top node, update top, free memory
    if (isEmpty()) {
        cout<<"Stack underflow"<<endl;
        return;
    }
    Node* temp = top;      // save current top
    top = top->next;       // move top to next node
    delete temp;           // free the old top's memory
}

int Stack::peek()
{// Part 6: return value of top node
    if (isEmpty()) {
        cout<<"stack underflow"<<endl;
        return -1;
    }
    return top->data;
}

bool Stack::isEmpty()
{// Part 7: return true if top == nullptr
    return top==nullptr;
}


void Stack::display()
{
    cout << "Stack elements:" << endl;
    Node* temp = top;
    while(temp != nullptr) {
        cout << temp->data << endl;  // endl instead of " "
        temp = temp->next;
    }
}
