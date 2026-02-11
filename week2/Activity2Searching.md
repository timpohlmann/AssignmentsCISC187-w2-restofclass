# Activity 2: Searching
## Task 1: How many steps would it take to perform a linear search for the number 8 in the ordered array, [2, 4, 6, 8, 10, 12, 13]? 
**Response**: Linear search checks elements one by one from the start so in this case it would take 4 steps. 

## Task 2: How many steps would binary search take for the previous example?
**Response**:Binary search starts by looking at the middle element, which in this case is 8, the element of interest. 1 step. 

## Task 3: What is the maximum number of steps it would take to perform a binary search on an array of size 100,000?
**Response**: Thinking of it logically, how many times can you divide 100k by 2 before going down to 1, which is log base 2 of 1000, which is in between 16 and 17
so the most amount of steps is 17 steps. 

## Task 4: Write a C++ program that implements both linear search and binary search algorithms using an array of 100,000 elements. The program should record and report the number of steps (comparisons) performed during each search operation. In addition, analyze and justify the observed behavior by providing a theoretical explanation using Big-O notation, demonstrating why linear search exhibits O(N)complexity and binary search exhibits O(logN)complexity.
**Response**: For linear search, the operation will always be proportional to the amount of elements there are, as it searches step by step until the value is reached. If the target value is the 6th value: 6 steps, the 1000th value: 1000 steps, so the relationship is linear. Binary search requires the elements to be sorted. Binary search has a time complexity of O(log N) because each comparison eliminates half of the remaining elements. As the input size grows, the number of steps increases very slowly, requiring only about log₂(N) comparisons in the worst case.
Code portion: 
```C++
#include <iostream>
using namespace std;

int linearSearch(int array[],int size, int target, int &steps) {
    for (int i=0; i<size; i++) {//loop through each array element
          steps++;//adds to the step count each iteration
        if (array[i]==target){return i;}//stores value
    } return -1;
}

int binarySearch(int array[], int size, int target, int &steps) {
    int low=0;
    int high=size-1;
    steps=0;
while (low<=high) {//loops through the values unitl low passes high, meaning all values have been checked
    steps++;
    int mid= (low+high)/2;//picks the index in the middle of array
    if (array[mid]==target) {//checks if value at middle index is the target
        return mid;}
    else if (array[mid]<target) {
        low=mid+1;}//if value below target, we only look at bigger values, making low=mid+1
    else {
        high =mid-1;//value is higher than target, we only look at smaller values, high goes down
    }
} return -1;
}

//going to create functions for linear and binary search
int main() {
    srand(time(0));//seed random generator
const int SIZE =100000;//How big the array is going to be
    int arr[SIZE];//creates the array with the size

    for (int i = 0; i < SIZE; i++) {
        arr[i]=i;}//creates an and fills it with elements 0 to 99999
    int randomindex= rand() % SIZE;
    int target=arr[randomindex];//picks a random index, which in this case corresponds to value in the array
    cout<< "the number of interest is: "<<target<<endl;

    int steps = 0;//initializing this, will be used in linear search function.
    int result = linearSearch(arr, SIZE, target, steps);
    if (result != -1) {//function returns -1 if value isnt found, this deals with that
        cout<<"Found at index: "<<result<<endl;
    }else{ cout<<"Not found"<<endl;}
    cout<<"Steps for linear search: "<<steps<<endl;//display the steps it took.

    int stepsb;//new variable for steps to distinguish,not needed i just wanted to differentiate.
    binarySearch(arr, SIZE, target, stepsb);//calling the function to find the amount of steps
    cout<<"Steps for binary search: "<<stepsb<<endl;
}
```
## Task 5: Write pseudocode for a randomized search algorithm that searches for a given key by randomly selecting indices without repetition. Use a dataset of 100,000 distinct elements, stored in a vector. Each element may be examined at most once during the search. Analyze and state the best-case, average-case, and worst-case time complexities of this algorithm using Big-O notation. Then, implement the algorithm in C++, using only the following standard headers: <vector> for data storage, <random> for random index generation, and <iostream> for input and output. The implementation should track and report the number of comparisons performed during the search. Finally, compare and contrast the randomized search algorithm with linear search and binary search in terms of time complexity, data requirements (such as ordering), and practical efficiency. Discuss scenarios in which each approach may be preferred, highlighting the advantages and limitations of randomized search relative to linear and binary search.
**Response**: Pseudocode/logic: Create boolean array 'visited' of size n, all false
While not all indices visited:
    Generate random index
    If index already visited:
        Continue to next iteration
    Mark index as visited
    If element at index equals key:
        Return found
Return not found
Analysis: Best case O(1), if the first random index contains the value of interest. The average case will be roughly linear O(N), meaning you will find the key after checking about n/2 elements(n=size). However, as you check more you are going to get more repeats, and will have to take more steps to skip them. The worst case scenario is O(n^2), because with each additional element you check, it increases the chance of getting repeats. If you have checked n-1 elements, every element besides the last one will be a repeat.  
Code: 
```C++
insert code
```

Compare and contrast: 
