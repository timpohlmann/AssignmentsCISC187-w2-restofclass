## Task 1: Following is the 'Word Builder' algorithm. Describe its space complexity in terms of Big O.
```
function wordBuilder(array) { 
		let collection = [];
		for(let i = 0; i < array.length; i++) { 
				for(let j = 0; j < array.length; j++) {
						if (i !== j) {
								collection.push(array[i] + array[j]);
						}
				}
		}
		return collection; 
}
```
**Response**:
The space complexity for this example is O(n^2) because of the fact that we are pairing the element in an array with every other element in it. 
## Task 2: Following is a function that reverses an array. Describe its space complexity in terms of Big O:
```
function reverse(array) { 
		let newArray = [];
		for (let i = array.length - 1; i >= 0; i--) { 
				newArray.push(array[i]);
		}
		return newArray;
}
```
**Response**: This case is O(N) because the final array will have the same amount of elements N as the input array.

## Task 3: Create a new function to reverse an array that takes up just O(1) extra space.
**Response**: 
```c++
#include <iostream>
using namespace std;

 void reversearray(int arr[], int size) {
  int left=0;
     int right=size - 1;
     while (left < right) {
         int temp = arr[left];
         arr[left] = arr[right];
         arr[right] = temp;
         right--;
         left++;
     }}


int main() {
     int array[5]={5,6,8,2,1,};

     reversearray(array,5);
     cout<<"Reversed Array"<<endl;
     for (int i=0;i<5;i++) {
         cout<<array[i]<<" ";

     }
 }
```

## Task 4: Following are three different implementations of a function that accepts an array of numbers and returns an array containing those numbers multiplied by 2. For example, if the input is [5,4,3,2,1] the output will be [10,8,6,4,2]
```
function doubleArray1(array) { 
	let newArray = [];

	for(let i = 0; i < array.length; i++) { 
		newArray.push(array[i] * 2);
	}
	return newArray; 
}


function doubleArray2(array) {
	for(let i = 0; i < array.length; i++) {
  	array[i] *= 2;
  }
	return array; 
}


function doubleArray3(array, index=0) { 
	if (index >= array.length) { return; }
  array[index] *= 2;
  doubleArray3(array, index + 1);
	return array; 
}
```

Fill in the table that follows to describe the efficiency of these three versions in terms of both time and space:


**Response**:


| Version    | Time complexity | Space complexity |
| ---------- | --------------- | ---------------- |
| Version #1 | O(N)            | O(N)             |
| Version #2 | O(N)            | O(1)             |
| Version #3 | O(N)            | O(N)             |

