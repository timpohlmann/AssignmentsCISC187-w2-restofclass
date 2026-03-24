# Binary Search Trees 
### Task 1: Imagine you were to take an empty binary search tree and insert the following sequence of numbers in this order: [1, 5, 9, 2, 4, 10, 6, 3, 8]. Draw a diagram showing what the binary search tree would look like. Remember, the numbers are being inserted in the order presented here
***Response***: https://drive.google.com/file/d/1shpmV3pD4fIF7Mu_Wl2VjbV3yoDuuRnq/view?usp=share_link

### Task 2: If a well-balanced binary search tree contains 1,000 values, what is the maximum number of steps it would take to search for a value within it?
***Response***: For a well balanced binary search tree the time complexity of the search operation is O(log(N)) which is just less than 10, so the maximum number of steps would be 10 steps. 
### Task 3: Write an algorithm that finds the greatest value within a binary search tree
***Response***: Start at the root node, check if a right child exists. If yes repeat the step(check if a right child exists). If no you have reached the rightmost node, return its value as the greatest
### Task 4: Write a code in C++ using the same array mentioned in #1 and implement a binary search tree. Only insertion operation is required. 
***Response***:
```C++
#include <iostream>
using namespace std;

struct Node {//struct for the nodes
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* insert(Node* node,int data) {
    if (node==nullptr) {
        return newNode(data);
    }
    if (data<node->data ) {
        node->left=insert(node->left,data);
    }
    else {
        node->right=insert(node->right,data);
    }
    return node;
}

int main() {
    int size=9;
    int array[9]={1,5,9,2,4,10,6,3,8};
    Node* root =nullptr;
    for (int i=0;i<size;i++) {
        root=insert(root,array[i]);
    }
}
```
