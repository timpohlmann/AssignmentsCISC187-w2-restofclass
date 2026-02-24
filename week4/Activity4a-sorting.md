# Activity 4a: sorting
## Task 1: Proof that, under the average-case scenario, the insertion sort has a time complexity of O(N^2) Draw a clear figure and show all the operations clearly. 
**Response**: For the average case scenario, assume that at iteration i, the inner loop performs about i/2 swaps.This is because in a random array, the element at index i is equally likley to belong in any of the i+1 positions, so on average it moves i/2 steps. The outer loop will run N-1 times because by the time index N-1 is reached the array will be fully sorted. If the average amount of swaps in the inner loop was i, the total amount of swaps would be (N^2-N)/2, but because the amount of inner loop swaps for this average case is i/2, the total amount of swaps becomes (N^2-N)/4. Because the dominant term is N^2 that makes the average-case time complexity of the swap-based insertion sort O(N^2).
drawing: https://drive.google.com/file/d/1LYs4M2amyaFBXskV5dND3PNPQQUIwiw-/view?usp=share_link or try this: 
[IMG_4895.pdf](https://github.com/user-attachments/files/25528343/IMG_4895.pdf)


## Task 2: At the start of the insertion sort, the index of the inspected value is set to 1. Change the index of the inspected value and verify that the total number of operations equals 20. Consider the worst-case scenario. Use N=5, where N is the number of elements.
**Response**: When starting at index 1 the total number of operations is 20(swaps+comparisons). In the worst case scenario when n=5 the beginning array is as follows. [5,4,3,2,1] In this case each index i will require i comparisions and i swaps.Starting at index one is one comparison and one swap, index 2 is 2 comparisons and 2 swaps, index 3 is 3 comparisons and 3 swaps, and index 4 has 4 comparisons and 4 swaps. So the total amount of operations is 2(1)+2(2)+2(3)+2(4)=20

## Task 3: The following function returns whether or not a capital “X” is present within a string. 
```Javascript
function containsX(string) {
	foundX = false;
	for(let i = 0; i < string.length; i++) { 
		if (string[i] === "X") {
			foundX = true; 
		}
	}
	return foundX; 
} 
```
### (a) What is this function’s time complexity regarding Big O Notation? (b) Then, modify the code to improve the algorithm’s efficiency for best- and average-case scenarios.
