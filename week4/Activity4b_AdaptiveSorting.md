### Part A:
# Tasks: Create an array of 50 integers. determine if the case is best worst or average based off a clearly defined threshold. Based on the analysis the program should automatically determine selection sort or insertion sort
**Response**: My threshold is based off inversions, which I am defining as a pair of any 2 elements that are in the wrong order relative to a sorted array. Selection sort always does (N^2)/2 comparison, where as Insertion sorts comparisons are directly related to the number of inversions(comparisons). Since the maximum amount of inversions is (N^2)/2 (fully reversed array), the average is (N^2)/4. Below this average insertion sort is faster, and above it, selection sort is faster. In this case that threshold (N^2)/4=625.
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
    '\n';

cout<<"Number of inversions: "<<inversions(array, size)<<endl;
    if (inversions(array,50) <625) {//calling inversions function to see how 'disordered' the array is
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
