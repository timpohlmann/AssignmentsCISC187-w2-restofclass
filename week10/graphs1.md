## Task 1: Create a theoretical graph using a pen and paper OR electronically. (2 points)
**Response**: https://drive.google.com/file/d/1jf1RjiqCLL4F0HWRXl15G0xzZnxgfyNV/view?usp=sharing

## Task 2: Implement the graph created in step 1 and apply breadth and depth-first search algorithms using C++. (6 points)
**Response**:
```C++
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;


void BFS(char startV, map<char, vector<char>>& adjList) {
    queue<char> frontierQueue;
    set<char> discoveredSet;

    // Enqueue startV and add to discovered
    frontierQueue.push(startV);
    discoveredSet.insert(startV);

    while (!frontierQueue.empty()) {//keep doing it until its empty
        char currentV = frontierQueue.front();
        frontierQueue.pop();//removes first in line element

        cout << currentV << " "; // "Visit" currentV

        for (char adjV : adjList[currentV]) {//range based for loop that looks at every adjV in current v
            if (!discoveredSet.contains(adjV)) {//if the adjV has not been visited yet
                frontierQueue.push(adjV);//add it to the queue of vertices we need to look at
                discoveredSet.insert(adjV);// and add it to the discovered set
            }
        }
    }
}
                            //this is a map, each char has a corresponding list of its adjacent vectors(manually inputted in main)
void DFS(char startV, map<char, vector<char>>& adjList) {
    stack<char> stack;//creating a stack for this algo
    set<char> visitedSet;

    stack.push(startV);//push starting vertex onto stack
    while (!stack.empty()) {//while theres something in the stack
        char currentV = stack.top();//look at the top save it to currentV
        stack.pop();//remove top of stack

        if (!visitedSet.contains(currentV)) {
            //if not visited yet
            cout << currentV << " ";
            visitedSet.insert(currentV);
            for (char adjV : adjList[currentV]) {//range based for loop that scans all the adjV @ the currentV
                stack.push(adjV);//push all neighbors onto the stack
            }

        }
    }

}


int main() {
    map<char, vector<char>> adjList;//is a map, first component is the vertex, second component is the list of adjacent
    adjList['A'].push_back('B');
    adjList['A'].push_back('C');
    adjList['A'].push_back('D');

    adjList['B'].push_back('A');
    adjList['B'].push_back('D');          //manually inputted all the adjacent vertices for each one, accounting for 'doubles'

    adjList['C'].push_back('A');
    adjList['C'].push_back('G');

    adjList['D'].push_back('A');
    adjList['D'].push_back('E');
    adjList['D'].push_back('H');
    adjList['D'].push_back('I');

    adjList['E'].push_back('D');
    adjList['E'].push_back('F');

    adjList['F'].push_back('E');
    adjList['F'].push_back('H');

    adjList['G'].push_back('C');
    adjList['G'].push_back('I');


    adjList['H'].push_back('D');
    adjList['H'].push_back('F');
    adjList['H'].push_back('I');

    adjList['I'].push_back('D');
    adjList['I'].push_back('G');
    adjList['I'].push_back('H');


   cout<<"BFS: ";
    BFS('A', adjList);
    cout<<endl;

    cout<< "DFS: ";
    DFS('A', adjList);
    cout<<endl;

    return 0;
    
}
```

## Task 3: Compare both search algorithms in the context of Big O notations. (2 points)
**Response**: Both are O(V+E) (V=vertices and E=edges) since both algorithms visit every vertex and edge once. The space complexity is different, for DFS it is O(H) where H is the maxium depth of the graph. In worst case(a straight line graph) it is O(V).  BFS is O(W) where W is the width of the graph. For the worst case of BFS it is O(V) if it is a very wide graph. 
