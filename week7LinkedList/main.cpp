#include <iostream>
#include "stack.h"//necessary
using namespace std;

int main() {
    Stack s;//creating stack s
    cout<<s.isEmpty()<<endl;
    s.push(10);//pushing 3 elements
    s.push(20);
    s.push(30);
    s.display();//displaying elements currently in stack 
    cout<<endl;
    cout<<"The value at the top of the current stack: "<<s.peek()<<endl;//showing the value at the top of the stack

    s.pop();//removing an element
    cout<<"Displaying after removing(pop): ";
    s.display();//showing elements currently in stack again

}
