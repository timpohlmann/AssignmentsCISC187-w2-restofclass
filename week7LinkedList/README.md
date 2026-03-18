# Linked List Stack Assignment
**Response**: I have the additional files in this same folder but attached the links to them in this file in attempt to make it easier to access.
Main.cpp : https://github.com/timpohlmann/AssignmentsCISC187-w2-restofclass/blob/b39ec338eb864e8945908a55144e54423103ade0/week7LinkedList/main.cpp

Stack.cpp : https://github.com/timpohlmann/AssignmentsCISC187-w2-restofclass/blob/59bc05bef2a76e548f91cce2c5ff1a613e7df5d7/week7LinkedList/stack.cpp

Stack.h : https://github.com/timpohlmann/AssignmentsCISC187-w2-restofclass/blob/32db659615d1341cf74032c4a9217fb44c140b83/week7LinkedList/stack.h


## Reflection questions:

#### Question 1:   Why is a linked list efficient for stack implementation?
****Response****: A linked list is efficient for stack implementation for a couple reasons. Push and pop are O(1) because you only ever remove or add from the top, which only updates one pointer. Unlike arrays a linked list is dynamic so it grows and shrinks as needed without wasting memory. Memory is created when an item is added and freed when an item is removed.
#### Question 2: What is the time complexity of push and pop operations?
****Response****: They are both O(1), they peform the same three steps every time. Push: 1. Create new node 2. Point it to current top 3. Update top. Pop: 1. Save current top 2. Move to next node 3. Delete saved node
#### Question 3: What happens if memory is not deallocated after pop?
****Response****: A memory leak occurs. The node is removed from the stack but still exists in memory with no pointer pointing to it, making it impossible to access or free. If this happens repeatedly, the program can slow down or potentially crash.
#### Question 4: Compare a stack implemented with an array versus a linked list.
****Response****: An array has fixed size and its size can be decided on beforehand. A linked list stack has dynamic size and only grows and shrinks as needed. An array allocates all memory upfront even if unused. A linked list only allocates memory when a node is 'created'. An array can overflow if the fixed size is exceeded. A linked list can only run out of memory if the entire system runs out. Performance speed is relatively similar but arrays tend to work slightly faster.
