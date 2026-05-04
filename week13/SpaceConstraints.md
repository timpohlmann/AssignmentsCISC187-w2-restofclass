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
**Response**:

## Task 3: Create a new function to reverse an array that takes up just O(1) extra space.
**Response**: 

## Task 4: 
**Response**:
