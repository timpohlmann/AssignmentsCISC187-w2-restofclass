### Part A:
# Tasks: Create an array of 50 integers. determine if the case is best, worst, or average based off a clearly defined threshold. Based on the analysis the program should automatically determine selection sort or insertion sort
**Response**: 
```C++
#include <iostream>
using namespace std;

int inversions(int arr[],int size) {
    //is when a pair of any indices (i, j) where i < j but array[i] > array[j]
    int count = 0;
   //for each element in the array we are looking for the values to the right of it that are smaller
    for (int i=0;i<size;i++) {
        for (int j=i+1;j<size;j++) {
            if (arr[i]>arr[j])
                count++;
        }
    }
    return count;//number of inversions
}


void selectionSort(int arr[], int size){
    for (int i=0;i<size;i++) {//outerloop
        int minIndex = i;//setting temporary variable
        for (int j=i+1;j<size;j++) {//going to the right looking at remaining elements
            if (arr[j]<arr[minIndex]) {//if the element on the right is less than the element being iterated over at the outer loop
                minIndex=j;//change that index to the min index
            }
        } int temp=arr[i];//swap value at i with the lowest value to the right of it, will be found at minIndex
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}

void insertionSort(int arr[], int size){
    for (int i=1;i<size;i++) {//outer loop starts at 2nd element in the array
        for (int j=i;j>0;j--) {//because we are comparing to elements on the left j is decreasing
            if (arr[j]<arr[j-1]) {//if element on the left is bigger than element on the right
                int tem=arr[j];//swapping the elements
                arr[j]=arr[j-1];
                arr[j-1]=tem;
            } else break;
        }
    }
}

void printArray(int arr[], int size) {//simple function to print elements of an array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int size=50;
    int array[50];
    for (int i = 0; i < 50; i++) {//filling an array
        array[i] = i + 1;}
    // Shuffle using Fisher-Yates
    srand(time(0));
    for (int i = 49; i > 0; i--) {
        int j = rand() % (i + 1);//randomly shuffling array
        // swap
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;}

cout<<"Array before sorting: "<<endl;
    printArray(array, size);//printing original array so user can gauge disorder
    
int invcount=inversions(array,50);
cout<<"Number of inversions: "<<invcount<<endl;
    if (invcount <625) {//checking inversions to see the amount of disorder, the threshold number is 625
cout<<"Method picked: insertion sort"<<endl<<"Sorted array: ";//Call insertion sort function and print the array
        insertionSort(array, 50);
        printArray(array, 50);
    }
    else {
        cout<<"Method picked: selection sort"<<endl<<"Sorted Array: ";//call selection sort function and print the array
        selectionSort(array, 50);
        printArray(array, 50);
    }
}

```
### Part B:
# Tasks: Using the same threshold defined in Part A:The user will input 50 integers. Without actually sorting the array, your program must analyze the order of elements.The program should classify the input as:Average CaseWorst Case. The program must then display the classification result.
**Response**: Following the logic from part A, an array with 625 or more inversions will be worst case, and anything less than 625 will be average case. 
```C++
#include <iostream>
using namespace std;

int inversions(int arr[],int size) {
    //is when a pair of any pair (i, j) where i < j but array[i] > array[j]
    int count = 0;
   //for each element in the array we are looking for the values to the right of it that are smaller
    for (int i=0;i<size;i++) {
        for (int j=i+1;j<size;j++) {
            if (arr[i]>arr[j])
                count++;
        }
    }
    return count;//number of inversions
}

void printArray(int arr[], int size) {//simple function to print elements of an array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int size=50;
    int array[50];

    for (int i = 0; i < 50; i++) {//outer for loop for user inputted array
        int num, duplicate;//declaring variables

        do {//begining of do-while
            duplicate = 0;//set duplicate count to 0
            cout << "Enter integer " << i + 1 << ": ";//promt user input
            cin >> num;

            for (int j = 0; j < i; j++) {//inner for loop, checks each value already in array
                if (array[j] == num) {//compares user input to value in array
                    duplicate = 1;
                    cout << "Duplicate! Try again." << endl;
                    break;//stops for loop if there is a duplicate
                }
            }
        } while (duplicate);//if duplicate stays at 0, it exits loop, and stores user inputted value into array
        array[i] = num;
    }


cout<<"Array before sorting: "<<endl;
    printArray(array, size);//printing original array so user can gauge disorder
    int invcount = inversions(array, size);

cout<<"Number of inversions: "<<invcount<<endl;
    if (invcount <625) {//checking inversions to see disorder
cout<<"Average case"<<endl;
    }
    else {
        cout<<"Worst case"<<endl;
    }
}
```
### Part C:
# Tasks: Give the threshold definiton to differentiate between cases and why. Why your program picks one sorting algorithm over another in specific scenarios. A brief discussion on how input order affects time complexity of selection sort and insertion sort.
**Response**: My threshold is based off inversions, which I am defining as a pair of any 2 elements that are in the wrong order relative to a sorted array. Selection sort always does (N^2)/2 comparison, where as Insertion sorts comparisons are directly related to the number of inversions(comparisons). Since the maximum amount of inversions is (N^2)/2 (fully reversed array), the average is (N^2)/4. Below this average insertion sort is faster, and above it, selection sort is faster. In this case that threshold (N^2)/4=625. 
Insertion sort is heavily dependent on input order, when the array is nearly sorted and requires few swaps, it runs close to O(N). Selection sort always runs at O(N^2), regardless of the amount of swaps needed. Both algorithms reach O(N^2) at worst case, but selection sort is better in this case because it doesnt perform a swap for every comparison like insertion sort. 
