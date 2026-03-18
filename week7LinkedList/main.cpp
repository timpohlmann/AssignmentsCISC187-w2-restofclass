#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack s;
    cout<<s.isEmpty()<<endl;
    s.push(10);//pushing
    s.push(20);
    s.push(30);
    s.display();
    cout<<endl;
    cout<<"The value at the top of the current stack: "<<s.peek()<<endl;

    s.pop();
    cout<<"Displaying after removing(pop): ";
    s.display();

}
