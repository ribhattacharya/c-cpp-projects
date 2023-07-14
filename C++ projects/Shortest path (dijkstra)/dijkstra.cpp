/*
Implement Dijkstra's algorithm
C++ for C Programmers: Part A
Week 3
Rishabh Bhattacharya
Jul 13th, 2023

This program implements Dijkstra's shortest path algorithm on a randomly generated weighted adjacency matrix. Given parameters like number  of nodes, density, etc., we can manipulate the graph to be sparse or dense. This is a way to increase the chances of finding a path between any two nodes. Low densities can work with larger graphs, while densities have to be greater in smaller graphs. A weight of INT_MAX (2147483647) between two nodes signifies that they are disconnected. Dijkstra's algorithm computes the shortest path to each node that has been expanded.


Program description: Create a random graph from given parameters, and use dijkstra's algorithm to compute average of all shortest paths.
------------------------------OUTPUT-------------------------------

Initialized graph with
-----------------------------------
Nodes:             50
Density:           0.2
Min. distance:     1
Max. distance:     10
Conn. matrix size: 50 x 50
Cost matrix size:  50 x 50

--------------------Computed paths--------------------
dist(1  ->  0) = 4         :  1 ->  0
dist(1  ->  1) = 0         :  1
dist(1  ->  2) = 6         :  1 -> 33 -> 24 -> 25 -> 27 ->  2
dist(1  ->  3) = 5         :  1 -> 33 ->  7 ->  3
dist(1  ->  4) = 9         :  1 -> 33 -> 24 -> 25 -> 27 ->  4
dist(1  ->  5) = 6         :  1 -> 29 -> 41 ->  5
dist(1  ->  6) = 7         :  1 -> 33 -> 24 -> 12 -> 48 ->  6
dist(1  ->  7) = 3         :  1 -> 33 ->  7
dist(1  ->  8) = 6         :  1 -> 33 -> 24 -> 40 ->  8
dist(1  ->  9) = 8         :  1 -> 33 ->  7 -> 45 ->  9
dist(1  -> 10) = 8         :  1 -> 33 -> 24 -> 12 -> 10
dist(1  -> 11) = 9         :  1 -> 29 -> 11
dist(1  -> 12) = 4         :  1 -> 33 -> 24 -> 12
dist(1  -> 13) = 7         :  1 -> 33 ->  7 ->  3 -> 13
dist(1  -> 14) = 8         :  1 -> 33 -> 24 -> 25 -> 14
dist(1  -> 15) = 7         :  1 -> 33 -> 24 -> 40 -> 15
dist(1  -> 16) = 8         :  1 -> 33 -> 24 -> 40 -> 34 -> 16
dist(1  -> 17) = 9         :  1 -> 29 -> 35 -> 17
dist(1  -> 18) = 6         :  1 -> 33 ->  7 -> 18
dist(1  -> 19) = 8         :  1 -> 33 -> 39 -> 19
dist(1  -> 20) = 7         :  1 -> 33 -> 24 -> 12 -> 20
dist(1  -> 21) = 8         :  1 -> 33 -> 24 -> 12 -> 20 -> 21
dist(1  -> 22) = 9         :  1 -> 33 ->  7 -> 18 -> 22
dist(1  -> 23) = 6         :  1 -> 29 -> 23
dist(1  -> 24) = 3         :  1 -> 33 -> 24
dist(1  -> 25) = 4         :  1 -> 33 -> 24 -> 25
dist(1  -> 26) = 7         :  1 -> 33 -> 24 -> 25 -> 27 -> 26
dist(1  -> 27) = 5         :  1 -> 33 -> 24 -> 25 -> 27
dist(1  -> 28) = 4         :  1 -> 33 -> 24 -> 28
dist(1  -> 29) = 4         :  1 -> 29
dist(1  -> 30) = 9         :  1 -> 29 -> 23 -> 30
dist(1  -> 31) = 8         :  1 -> 33 -> 31
dist(1  -> 32) = 6         :  1 -> 29 -> 32
dist(1  -> 33) = 2         :  1 -> 33
dist(1  -> 34) = 7         :  1 -> 33 -> 24 -> 40 -> 34
dist(1  -> 35) = 7         :  1 -> 29 -> 35
dist(1  -> 36) = 8         :  1 -> 29 -> 41 -> 36
dist(1  -> 37) = 10        :  1 -> 29 -> 41 -> 36 -> 37
dist(1  -> 38) = 9         :  1 -> 29 -> 38
dist(1  -> 39) = 4         :  1 -> 33 -> 39
dist(1  -> 40) = 5         :  1 -> 33 -> 24 -> 40
dist(1  -> 41) = 5         :  1 -> 29 -> 41
dist(1  -> 42) = 5         :  1 -> 33 -> 42
dist(1  -> 43) = 6         :  1 ->  0 -> 43
dist(1  -> 44) = 7         :  1 ->  0 -> 44
dist(1  -> 45) = 7         :  1 -> 33 ->  7 -> 45
dist(1  -> 46) = 6         :  1 -> 33 ->  7 -> 46
dist(1  -> 47) = 9         :  1 ->  0 -> 43 -> 47
dist(1  -> 48) = 6         :  1 -> 33 -> 24 -> 12 -> 48
dist(1  -> 49) = 7         :  1 -> 33 -> 49

Path found from 1 to 3: Yes. Average distance between two nodes is 6.4898.
*/
#include<iostream>
#include<cstdlib>

#include "include/Graph.h"
#include "include/ShortestPath.h"


int main(int argc, char **argv) {
    srand(time(0));     // Output is provided with srand(7);
    
    Graph graph(50, 0.2, 1, 10, false);         // Create graph
    ShortestPath shortest_path(1, 27, graph);   // Initialize shortest path
    
    return 0;
}