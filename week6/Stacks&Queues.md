# Stacks and Queues Assignment
https://d-khan.github.io/ds/stacks.html
## Task 1: Using Figure 17 as a model, in the book Data Structures in C++, illustrate the result of each operation in the sequence PUSH(S,4), PUSH(S,1), PUSH(S,3), POP(S), PUSH(S,8), and POP(S) on an initially empty stack S stored in array S[1..6]. Code is not required. 3 pts
**Response**: https://drive.google.com/file/d/1N8Pkj7S52FE_BcFGXSYfiRkqJ1GQqFpv/view?usp=sharing 
## Task 2: Using Figure 18 as a model, in the book Data Structures in C++, illustrate the result of each operation in the sequence ENQUEUE(Q,4), ENQUEUE(Q,1), ENQUEUE(Q,3), DEQUEUE(Q), ENQUEUE(Q,8), and DEQUEUE(Q) on an initially empty queue Qstored in array Q[1..6]. Code is not required. 3 pts
**Response**:https://drive.google.com/file/d/1hIO-yjp6lMfHCtTsmwSMDRK0kIb5V7Pw/view?usp=share_link
## Task 3: Rewrite ENQUEUE and DEQUEUE to detect underflow and overflow of a queue. (see Listings 4 & 5 in the book). Code is not required. 1 pt
**Response**: First of all overflow can only happen when enqueueing, and underflow when dequeueing. 
To prevent overflow we can modify enqueue to check if the queue is full before adding. If it's full, report overflow and do nothing. Otherwise we can proceed normally and add the desired value to the queue.
To prevent underflow we can modify dequeue to check if the queue is empty. If it's empty, report underflow and do nothing. Otherwise we can proceed normally and remove the value from the end of the queue.
## Task 4: A stack allows insertion and deletion of elements at only end, and a queue allows insertion at one end and deletion at the other end, a deque (double-ended queue) allows insertion and deletion at both ends. Write four O(1)-time procedures to insert elements into and delete elements from both ends of a deque implemented by an array. Code is not required. 3 pts
**Response**:
