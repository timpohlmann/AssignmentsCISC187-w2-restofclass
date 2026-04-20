## Task 1: Explain with the help of an example "Why Dijkstra's algorithm fails on negative weights".
**Response**:
this is the example graph: https://drive.google.com/file/d/1YI5fkrMhm6b4-HHPdC2comIsv-yzIgxe/view?usp=sharing
By performing Dijkstras algorithm on this graph 
1. I will start at A.
2. C has the shortest path from A so we can finalize its length to 3, and update neighbors, B=8 D=20
3. After visiting C, we update D to 7 and 5 to F, and next we visit F.
4. When we visit F we update and finalize E to be 6. 
5. Next we visit D(cost 7) and update E to be -10, which fails because E is alreaduy finalized to 6.
6. Finally B gets visited and stays at 8

However it is important that Dijkstras algorithm doesn't always fail when there is a negative, it depends on the case. 
Additionally in the Case of our exmaple when performing the Cycle from C->D->E->F and back to C we get a negative weight for the overall cycle, so theoretically every shortest-path cost for this graph would be infinitely negative. 
