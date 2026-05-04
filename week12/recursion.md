## Task 1:
 The following function prints every other number from a low number to a high number. For example, if low is 0 and high is 10, it would print:
```
0
2
4
6
8
10
```
Identify the base case in the function:
```
def print_every_other(low, high) 
    return if low > high
    puts low
    print_every_other(low + 2, high)
end
```
**Response**: The base case in this function is if low>high. Low increases by 2 with every recursion, and high stays the same. 
## Task 2: 

 My kid was playing with my computer and changed my factorial function so that it computes factorial based on (n - 2) instead of (n - 1). Predict what will happen when we run factorial(10) using this function:

```
def factorial(n)
    return 1 if n == 1
    return n * factorial(n - 2)
end
```
**Response**: For n=10 it will cause stack overflow because the base case will never be satisfied due to the fact that 10-2n will never be 1. For Odd numbers this could work as the base case could be satisfied.
## Task 3:
Following is a function in which we pass in two numbers called low and high. The function returns the sum of all the numbers from low to high. For example, if low is 1, and high is 10, the function will return the sum of all numbers from 1 to 10, which is 55. However, our code is missing the base case, and will run indefinitely! Fix the code by adding the correct base case:
```
def sum(low, high)
    return high + sum(low, high - 1)
end
```
**Response**: 
```
def sum(low, high)
    return high if low >= high  # base case
    return high + sum(low, high - 1)
end
```
This say low is 3 and high is 4, then we get 4 + sum(3,3) which gets to satisfy the base case and finally return 7 with our orignal call of the function
## Task 4:
Here is an array containing both numbers as well as other arrays, which in turn contain numbers and arrays:
```
array=[ 1, 
        2, 
        3,
        [4, 5, 6],
        7,
        [8,
          [9, 10, 11,
            [12, 13, 14]
          ] 
        ],
        [15, 16, 17, 18, 19,
          [20, 21, 22,
            [23, 24, 25,
              [26, 27, 29]
            ], 30, 31 
          ], 32
        ], 33 
      ]
```
Write a recursive function that prints all the numbers (and just numbers).
**Response**:
```
function printnumbers(array)
for each element in array
if element is an array:
    printnumbers(element)
    else:
    print element
```
```c++
#include <iostream>
#include <variant>
#include <vector>

// Forward declaration
struct Element;

using Array = std::vector<Element>;

struct Element {
    std::variant<int, Array> value;
};

void printNumbers(const Array& arr) {
    // Iterate over each element in the current array
    for (const auto& elem : arr) {

        // Check if element is a plain integer (not a nested array)
        if (std::holds_alternative<int>(elem.value)) {

            // It's a number  print it
            std::cout << std::get<int>(elem.value) << "\n";

        } else {
            // It's a nested array so recurse into it.
            // printing its numbers and recursing further if it finds more nested arrays.
            // The recursion unwinds naturally once an array is reached with no further nesting
            printNumbers(std::get<Array>(elem.value));
        }
    }
    // When the loop ends, we've fully processed this array level.
    // Control returns to the caller (either main, or a previous recursive call).
}
int main() {
    Array array = {
        {1}, {2}, {3},
        {Array{ {4}, {5}, {6} }},
        {7},
        {Array{ {8}, {Array{ {9}, {10}, {11}, {Array{ {12}, {13}, {14} }} }} }},
        {Array{ {15}, {16}, {17}, {18}, {19},
            {Array{ {20}, {21}, {22},
                {Array{ {23}, {24}, {25},
                    {Array{ {26}, {27}, {29} }}
                }}, {30}, {31}
            }}, {32}
        }},
        {33}
    };

    printNumbers(array);
    return 0;
}



```
