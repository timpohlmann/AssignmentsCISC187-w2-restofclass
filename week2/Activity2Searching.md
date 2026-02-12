or# Activity 2: Searching
## Task 1: How many steps would it take to perform a linear search for the number 8 in the ordered array, [2, 4, 6, 8, 10, 12, 13]? 
**Response**: Linear search checks elements one by one from the start so in this case it would take 4 steps. 

## Task 2: How many steps would binary search take for the previous example?
**Response**:Binary search starts by looking at the middle element, which in this case is 8, the element of interest. 1 step. 

## Task 3: What is the maximum number of steps it would take to perform a binary search on an array of size 100,000?
**Response**: Thinking of it logically, how many times can you divide 100k by 2 before going down to 1, which is log base 2 of 1000, which is in between 16 and 17
so the most amount of steps is 17 steps. 

## Task 4: Write a C++ program that implements both linear search and binary search algorithms using an array of 100,000 elements. The program should record and report the number of steps (comparisons) performed during each search operation. In addition, analyze and justify the observed behavior by providing a theoretical explanation using Big-O notation, demonstrating why linear search exhibits O(N)complexity and binary search exhibits O(logN)complexity.
**Response**: For linear search,the steps in the operation will always be proportional to the amount of elements there are, as it searches step by step until the value is reached. If the target value is the 6th value: 6 steps, the 1000th value: 1000 steps, so the relationship is linear. Binary search requires the elements to be sorted. Binary search has a time complexity of O(log N) because each comparison eliminates half of the remaining elements. As the input size grows, the number of steps increases very slowly, requiring only about log₂(N) comparisons in the worst case.
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
        arr[i]=i;}//fills it with elements 0 to 99999
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
**Response**: Pseudocode/logic: Fill a vector array with 100k elements.
Create boolean array 'visited'.
of size n, all false.
While not all indices visited:
    Generate random index
    If index already visited:
        Continue to next iteration
    Mark index as visited
    create a counter for total operations(visited indexes + collisions)
    If element at index equals key:
        Return found
Return not found

Analysis: Best case O(1), if the first random index contains the value of interest. The average case will be roughly linear O(N), meaning you will find the key after checking about n/2 elements(n=size). However, as you check more you are going to get more repeats, and will have to take more steps to skip them. The worst case scenario is O(n^2), because with each additional element you check, it increases the chance of getting repeats. If you have checked n-1 elements, every element besides the last one will be a repeat.  
Code: 
```C++
#include <iostream>
#include <vector>
#include <random>
using namespace std;

//pseudo code: Create boolean array 'visited' of size n, all false
//While not all indices visited:
    //Generate random index
   // If index already visited:
      //  Continue to next iteration
   // Mark index as visited
   // If element at index equals key:
    //    Return found

int main() {
    const int SIZE=100000;
    vector<int> data(SIZE);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, SIZE - 1);

    int key = dist(gen); // Random key between 0 and 99999

    cout << "Searching for key: " << key << endl;

    for (int i=0;i<SIZE;i++) {//in this case we are filling with distinct values(not random)
        data[i]=i;//the data order doesnt matter for testing our algorithm
    }
    bool visited[SIZE]={false};//creates bool array 'visited', every element stasrts as false
    int checkedcount=0;
    int repeats=0;
    

    while (checkedcount<SIZE) {
        int randomIndex=dist(gen);//generate random index

        if (visited[randomIndex]) {//if the index has already been checked add to repeat counter
            repeats++;
            continue;//already visited try again
        }//only gets past here if its a new value
visited[randomIndex]=true;//set the random index to true in the visited boolean array
        checkedcount++;//add to the count of checked indices 
        
        if (data[randomIndex]==key) {//if thats the number of interest print the info
            cout<<"Key found at index: "<<randomIndex<<endl;
            cout<<"total amount of operations: "<< checkedcount+repeats <<endl;
            return 0;
        }

    }
}

```

Compare and contrast: The only one with data requirements is binary search which requires sorted data to proceed. As for the time complexities I will start with linear search. Linear search has time complexity O(N) with best case being O(1) if the key is at the first position, average case and worst case are both O(N) as the keys are found halfway through or at the end, respectively. For binary search the best case is O(1) where the key is in the middle position on first check. The average and worst case are both O(logN). For randomized search the best case is O(1) when the first random pick finds the key. The average case is O(N) where it finds the key after checking ~n/2 elements, with ~n/4 collisions, totaling ~0.75n operations. The worst case is O(N^2) where there would be extreme collision when most indices are already checked. Linear search is effective in small datasets that need to be searched once or twice. Binary search is best for large sorted datasets(n>10,000), or Data that will be searched multiple times. Randomized search is almost never the best option. 
