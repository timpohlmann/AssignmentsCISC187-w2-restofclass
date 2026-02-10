# Activity 2: Searching
## Task 1: How many steps would it take to perform a linear search for the number 8 in the ordered array, [2, 4, 6, 8, 10, 12, 13]? 
**Response**: Linear search checks elements one by one from the start so in this case it would take 4 steps. 

## Task 2: How many steps would binary search take for the previous example?
**Response**:Binary search starts by looking at the middle element, which in this case is 8, the element of interest. 1 step. 

## Task 3: What is the maximum number of steps it would take to perform a binary search on an array of size 100,000?
**Response**: Thinking of it logically, how many times can you divide 100k by 2 before going down to 1, which is log base 2 of 1000, which is in between 16 and 17
so the most amount of steps is 17 steps. 

## Task 4: Write a C++ program that implements both linear search and binary search algorithms using an array of 100,000 elements. The program should record and report the number of steps (comparisons) performed during each search operation. In addition, analyze and justify the observed behavior by providing a theoretical explanation using Big-O notation, demonstrating why linear search exhibits O(N)complexity and binary search exhibits O(logN)complexity.
**Response**: 
