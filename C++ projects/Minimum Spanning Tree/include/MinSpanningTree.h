#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<limits>
#include<stack>
#include<queue>
#include<unordered_set>

#include "Graph.h"
#include "PriorityQueue.h"

using namespace std;

class Node {
    /*
    DESC: Maintain the node identifier (val), along with its predecessor.
    */
    int val;
    int prev;

public:
    Node(int data = 0, int prev_node = -1): val(data), prev(prev_node) {}
    int getVal() {return val;}
    int getPrevNode() {return prev;}
    void setPrevNode(int node) {prev = node; return;}
};


class MinSpanningTree {
    /*
    DESC: Implements the minimum spanning tree algorithm and computes the tree cost.
    */
    const int start;
    Graph G;
    
    vector<Node> nodes;
    unordered_set<int> CLOSED;
    PriorityQueue OPEN;
    int tree_length;

public:
    MinSpanningTree(Graph& graph, const int source) : G(graph), start(source), nodes(vector<Node>(graph.getNumNodes())), tree_length(0) {
        for (int i = 0; i < graph.getNumNodes(); i++)
            nodes.push_back(Node(i, -1));
        
        PrimsAlgorithm();
    }

    bool isInCLOSED (const int x) {return CLOSED.find(x) != CLOSED.end();}

    void PrimsAlgorithm() {
        /*
        DESC: Runs Prim's algorithm on the given graph and start node.
        */
        OPEN.push(start, 0);

        while(!OPEN.empty()) {
            
            if (isInCLOSED(OPEN.top().first)) {
                OPEN.pop();
                continue;
            }
            
            int node_to_expand = OPEN.top().first;
            tree_length += (OPEN.top().second);
            cout << "Node expanded: " << setw(2) << right << node_to_expand << " with cost: " << setw(2) << right << OPEN.top().second << '\n';
            OPEN.pop();
            CLOSED.insert(node_to_expand);

            vector<int> neighbours = G.getNeighbours(node_to_expand);
            for (int neighbour : neighbours) {
                if (isInCLOSED(neighbour)) continue;    // Don't revisit CLOSED nodes.

                OPEN.push(neighbour, G.getCost(node_to_expand, neighbour));
            }
        }

        cout << "\n\nMinimum Spanned Tree Cost: " << tree_length << '\n';    
    }
};

#endif // SHORTESTPATH_H