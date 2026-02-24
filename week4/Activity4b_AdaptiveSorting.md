### Part A:
# Tasks: Create an array of 50 integers. determine if the case is best worst or average based off a clearly defined threshold. Based on the analysis the program should automatically determine selection sort or insertion sort
Notes for now: Selection sort is always O(N^2), and insertion sort in better cases is more efficient. for worst case or close to worst case Selection sort is better. 
Base the threshold off inversions
An inversion is any pair (i, j) where i < j but array[i] > array[j] — basically any pair of elements that are out of order.
if number of inversions are <(N^2)/4  use insertion sort
if number of inversions are > or = (N^2)/4 use selection sort. 
So im thinking fill array randomly with numbers from 1 to 50 with no repeats, then create a function to analyze the inversions
then call a function based on the result. 
