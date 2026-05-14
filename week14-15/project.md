## Task 1:
You’re working on software that analyzes sports players. Following are two arrays of players of different sports:

```
basketball_players = [
      {first_name: "Jill", last_name: "Huang", team: "Gators"},
      {first_name: "Janko", last_name: "Barton", team: "Sharks"},
      {first_name: "Wanda", last_name: "Vakulskas", team: "Sharks"},
      {first_name: "Jill", last_name: "Moloney", team: "Gators"},
      {first_name: "Luuk", last_name: "Watkins", team: "Gators"}
]

football_players = [
      {first_name: "Hanzla", last_name: "Radosti", team: "32ers"},
      {first_name: "Tina", last_name: "Watkins", team: "Barleycorns"},
      {first_name: "Alex", last_name: "Patel", team: "32ers"},
      {first_name: "Jill", last_name: "Huang", team: "Barleycorns"},
      {first_name: "Wanda", last_name: "Vakulskas", team: "Barleycorns"}
]
```

If you look carefully, you’ll see that some players participate in more than one sport. Jill Huang and Wanda Vakulskas play both basketball *and* football.

You are to write a function that accepts two arrays of players and returns an array of the players who play in *both* sports. In this case, that would be:

`["Jill Huang", "Wanda Vakulskas"]`

While there are players who share first names and players who share last names, we can assume there’s only one person who has a particular *full* name (meaning first *and* last name).

We can use a nested-loops approach, comparing each player from one array against each player from the other array, but this would have a runtime of $O(N * M)$. 

**Your job is to optimize the function so that it can run just $O(N + M)$.**
**Response**: 
```c++
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

struct Player {
    std::string first_name;//the struct for the player which will help make the vector
    std::string last_name;
    std::string team;
};

std::vector<std::string> find_players_in_both_sports(
    std::vector<Player> basketball_players, 
    std::vector<Player> football_players) 
{
    // Step 1: O(N) - store basketball players in a hash set
    std::unordered_set<std::string> basketball_set;
    for (Player player : basketball_players) {//for loop datatype(struct player) and then giving variable name 'player'
        std::string full_name = player.first_name + " " + player.last_name;//creating new var
        basketball_set.insert(full_name);//adding to the set
    }

    // Step 2: O(M) - check each football player against the set
    std::vector<std::string> both_sports;//creating a vector for players in both sports
    for (Player player : football_players) {
        std::string full_name = player.first_name + " " + player.last_name;
        if (basketball_set.count(full_name)) {//if its included in the set 
            both_sports.push_back(full_name);//push this into the vector
        }
    }

    return both_sports;
}

int main() {
    std::vector<Player> basketball_players = {
        {"Jill", "Huang", "Gators"},
        {"Janko", "Barton", "Sharks"},
        {"Wanda", "Vakulskas", "Sharks"},
        {"Jill", "Moloney", "Gators"},
        {"Luuk", "Watkins", "Gators"}
    };

    std::vector<Player> football_players = {//vector of type player, so it has 3 attributes each
        {"Hanzla", "Radosti", "32ers"},
        {"Tina", "Watkins", "Barleycorns"},
        {"Alex", "Patel", "32ers"},
        {"Jill", "Huang", "Barleycorns"},
        {"Wanda", "Vakulskas", "Barleycorns"}
    };

    std::vector<std::string> result = find_players_in_both_sports(
        basketball_players, 
        football_players
    );

    std::cout << "Players in both sports:" << std::endl;
    for (std::string name : result) {
        std::cout << name << std::endl;
    }

    return 0;
}
```
## Task 2

You’re writing a function that accepts an array of distinct integers from 0, 1, 2, 3...up to N. However, the array will be missing one integer, and your function is to *return the missing one.*

For example, this array has all the integers from 0 to 6, but is missing the 4:

```
[2, 3, 0, 6, 1, 5]
```

Therefore, the function should return 4.

The next example has all the integers from 0 to 9, but is missing the 1:

```
[8, 2, 3, 9, 4, 7, 5, 0, 6]
```

In this case, the function should return the 1.

Using a nested-loops approach would take up to $O(N^2)$. 

**Your job is to optimize the code so that it has a runtime of $
**Response**:
```c++
#include <iostream>
#include <vector>

int findmissingnumber(std::vector<int>& arr) {
    int n = arr.size();//because theres a missing number the final number of the array n will be equal to its size
    int expectedsum= n*(n+1)/2;//summing up all the numbers from 0 to N

    int actualsum=0;
    for (int num:arr) {//for loop to find the actual sum
        actualsum += num;
    }
return expectedsum-actualsum;
}

int main() {//testing top make sure it works
    std::vector<int> arr1={2, 3, 0, 6, 1, 5};
    std::vector<int> arr2={8, 2, 3, 9, 4, 7, 5, 0, 6};

    std::cout << findmissingnumber(arr1) << std::endl;
    std::cout << findmissingnumber(arr2) << std::endl;
}
```
## Task 3

You’re working on some more stock-prediction software. The function you’re writing accepts an array of predicted prices for a particular stock over the course of time.

For example, this array of seven prices:

```
[10, 7, 5, 8, 11, 2, 6]
```

predicts that a given stock will have these prices over the next seven days. (On Day 1, the stock will close at \$10; on Day 2, the stock will close at $7; and so on.)

Your function should calculate the greatest profit that could be made from a single “buy” transaction followed by a single “sell” transaction.

In the previous example, the most money could be made if we bought the stock when it was worth \$5 and sold it when it was worth \$11. This yields a profit of $6 per share.

Note that we could make even more money if we buy and sell multiple times, but for now, this function focuses on the most profit that could be made from just *one* purchase followed by *one* sale.

Now, we could use nested loops to find the profit of every possible buy and sell combination. However, this would be $O(N^2)$ and too slow for our hotshot trading platform. 

**Your job is to optimize the code so that the function clocks in at just $O(N)$.**
**Response**:
```c++
#include <iostream>

int maxprofit(int arr[], int size) {
    int bestprofit=0;
    int minsofar=arr[0];//the minimum buying price
    for (int i=0;i<size;i++){
        int potentialprofit=arr[i]-minsofar;//evaluates the potential profit which is the sell price(arr[i]-the min buying price)
        if (potentialprofit>bestprofit) bestprofit=potentialprofit;
        if (arr[i]<minsofar) {
            minsofar=arr[i];
        }

    }
return bestprofit;
}

int main() {
    int arr[] = {10, 7, 5, 8, 11, 2, 6};//testing it with the example
    int size =7;
    std::cout <<"The best profit is: "<< std::endl;
    std::cout << maxprofit(arr, size);
}
```
## Task 4

You’re writing a function that accepts an array of numbers and computes the highest product of any two numbers in the array. At first glance, this is easy, as we can just find the two greatest numbers and multiply them. However, our array can contain negative numbers and look like this:

```
[5, -10, -6, 9, 4]
```

We could use nested loops to multiply every possible pair of numbers, but this would take $O(N^2)$ time. **Your job is to optimize the function so that it’s a speedy $O(N)$.**
**Response**: 
```c++
#include <iostream>

int highestproduct(int arr[], int size) {
    int largest =std::max(arr[0], arr[1]);//initializing variables for largest, smallest
    int secondlargest=std::min(arr[0], arr[1]);
    int smallest=std::min(arr[0], arr[1]);
    int secondsmallest=std::max(arr[0], arr[1]);

    for (int i = 2; i < size; i++) {
        if (arr[i] > largest) {//updating counter for largest, 2nd largest
            secondlargest =largest;
            largest=arr[i];
        }
        else if (arr[i] > secondlargest) {
            secondlargest=arr[i];
        }

        if (arr[i] < smallest) {//updating counter for smallest, 2nd smallest
            secondsmallest=smallest;
            smallest=arr[i];
        }
        else if (arr[i] < secondsmallest) {
            secondsmallest=arr[i];
        }
    }
    int max = std::max(largest* secondlargest, smallest* secondsmallest);
    return max;
}

int main() {
    int arr[]={5,-10,-6,9,4};//running the example
    int size =5;
    std:: cout<<"The largest product possible in that array was: "<<std::endl;
    std::cout << highestproduct(arr, size);
}
```
## Task 5

You’re creating software that analyzes the data of body temperature readings taken from hundreds of human patients. These readings are taken from healthy people and range from 97.0 degrees Fahrenheit to 99.0 degrees Fahrenheit. An important point: within this application, *the decimal point never goes beyond the tenth place.*

Here’s a sample array of temperature readings:

```
[98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1]
```

You are to write a function that sorts these readings from lowest to highest.

Using a classic sorting algorithm such as Quicksort would take $O(N log N)$. However, in this case, writing a faster sorting algorithm is possible.

Yes, that’s right. Even though you’ve learned that the fastest sorts are $O(N log N)$, this case is different. Why? In this case, there are limited possibilities for the readings. In such a case, we can sort these values in $O(N)$. It may be $N$ multiplied by a constant, but that’s still considered $O(N)$.
**Response**: 
```c++
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<double> sort_temperatures(std::vector<double> readings) {
    // Step 1: initialize hashmap with all possible temps as whole numbers
    std::unordered_map<int, int> counts;
    for (int i = 970; i <= 990; i++) {
        counts[i] = 0;
    }

    // Step 2: O(N) - count each temperature
    for (double temp : readings) {
        int key = (int)(temp * 10 + 0.5); // multiply by 10 to avoid float issues, truncate
        counts[key]++;
    }

    // Step 3: O(N) - reconstruct sorted array
    std::vector<double> sorted;
    for (int i = 970; i <= 990; i++) {
        for (int j = 0; j < counts[i]; j++) {
            sorted.push_back(i / 10.0); // divide back by 10 to get original temp
        }
    }

    return sorted;
}

int main() {
    std::vector<double> readings = {98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1};

    std::vector<double> result = sort_temperatures(readings);//sorting them

    for (double temp : result) {//for each temp in sorted temp, output it
        std::cout << temp << std::endl;
    }

    return 0;
}
```
## Task 6

You’re writing a function that accepts an array of unsorted integers and returns the length of the *longest consecutive sequence* among them. The sequence is formed by integers that increase by 1. For example, in the array:

```
[10, 5, 12, 3, 55, 30, 4, 11, 2]
```

the longest consecutive sequence is 2-3-4-5. These four integers form an increasing sequence because each integer is one greater than the previous one. While there’s also a sequence of 10-11-12, it’s only a sequence of three integers. In this case, the function should return 4, since that’s the length of the *longest* consecutive sequence that can be formed from this array.

One more example:

```
[19, 13, 15, 12, 18, 14, 17, 11]
```

This array’s longest sequence is 11-12-13-14-15, so the function would return 5.

**Your job is to optimize the function so that it takes $O(N)$ time.**
**Response**:
Maybe use some sort of tree?

