/*
Implement Prim's algorithm
C++ for C Programmers: Part A
Week 4
Rishabh Bhattacharya
Jul 15th, 2023

Program description: This program implements Prim's algorithm on a graph that is read from input.txt and returns the length of the minimum spanning tree.

------------------------------OUTPUT-------------------------------
Node expanded:  0 with cost:  0
Node expanded:  2 with cost:  2
Node expanded:  9 with cost:  1
Node expanded: 13 with cost:  3
Node expanded: 12 with cost:  3
Node expanded: 17 with cost:  1
Node expanded: 11 with cost:  1
Node expanded: 14 with cost:  1
Node expanded: 18 with cost:  1
Node expanded:  5 with cost:  1
Node expanded:  6 with cost:  1
Node expanded:  3 with cost:  1
Node expanded:  1 with cost:  1
Node expanded: 16 with cost:  2
Node expanded: 10 with cost:  3
Node expanded: 15 with cost:  2
Node expanded: 19 with cost:  2
Node expanded:  7 with cost:  2
Node expanded:  4 with cost:  1
Node expanded:  8 with cost:  1


Minimum Spanned Tree Cost: 30
*/

#include<iostream>
#include<cstdlib>

#include "include/Graph.h"
#include "include/MinSpanningTree.h"



int main(int argc, char **argv) {
    srand(time(0));     // Output is provided with srand(7);
    string file_name = (argc > 1)? argv[1] : "input.txt";
    
    // Graph graph(50, 0.2, 1, 10, false);     // Create random graph
    Graph graph(file_name, false);          // Read graph
    MinSpanningTree mst(graph, 0);          // Compute MST
    
    return 0;
}