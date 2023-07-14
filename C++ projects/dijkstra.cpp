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
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<queue>
#include<unordered_set>
#include<stack>
#include<limits>


using namespace std;

class Node {
    /*
    DESC: Maintain the node identifier (val), along with its cost from start and predecessor.
    */
    int val;
    int cost_from_start;
    int prev;

public:
    Node(int data = 0, int g = INT_MAX, int prev_node = -1): val(data), cost_from_start(g), prev(prev_node) {}
    int getVal() {return val;}
    int getCostFromStart() {return cost_from_start;}
    void setCostFromStart(int g) {cost_from_start = g; return;}
    int getPrevNode() {return prev;}
    void setPrevNode(int node) {prev = node; return;}
};

class Graph {
    /*
    DESC: Graph class to create and process the graph.
    */
    const int n_nodes;
    const double density;
    const int DIST_MIN, DIST_MAX;
    vector<vector<bool> > conn_matrix;
    vector<vector<int> > costs;
    
    double prob() {return static_cast<double>(rand()) / RAND_MAX;}
    
    void createGraph() {
        /*
        DESC: Create a random graph.
        */
        for (int i = 0; i < n_nodes; i++) {
            for (int j = i; j < n_nodes; j++) {
                // No loops, so a node can't lead to itself
                conn_matrix[i][j] = conn_matrix[j][i] = (i == j)? false : (prob() < density);
                if (i == j) costs[i][j] = costs[j][i] = 0;
                
                // Add random weights to edges which are connected
                if (conn_matrix[i][j] == true)
                    costs[i][j] = costs[j][i] = rand() % (DIST_MAX - DIST_MIN + 1) + DIST_MIN;
            }
        }
    }

public:
    Graph(int n = 50, double d = 0.1, int dist_min = 1.0, int dist_max = 10.0, bool print_graph = false)
        : n_nodes(n), density(d), DIST_MIN(dist_min), DIST_MAX(dist_max), 
            conn_matrix(vector<vector<bool> > (n, vector<bool> (n, false))),
            costs(vector<vector<int> > (n, vector<int> (n, INT_MAX))) {
        const int text_width = 20;
        
        cout << "\nInitialized graph with\n" << string(35, '-') 
            << setw(text_width) << left << "\nNodes:" <<  n_nodes
            << setw(text_width) << left  << "\nDensity:" << density
            << setw(text_width) << left  << "\nMin. distance:" << DIST_MIN
            << setw(text_width) << left  << "\nMax. distance:" << DIST_MAX
            << "\nConn. matrix size: " << conn_matrix.size() << " x " << conn_matrix[0].size()
            << "\nCost matrix size:  " << costs.size() << " x " << costs[0].size() << endl;
        
        createGraph();

        if (print_graph) {
            printMatrix(conn_matrix);
            printMatrix(costs);
        }
    }
    
    template <typename printable>
    void printMatrix(vector<vector<printable> >& matrix) {
        /*
        DESC: Print the graph matrices (adjacency matrix or connectivity matrix).

        INPUTS:
            vector<vector<printable> >& matrix: cost or connectivity matrix.
        */
        for (int i = 0; i < n_nodes; i++) {
            for (int j = 0; j < n_nodes; j++)
                cout << setw(10) << right << matrix[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
    }

    void printGraphAsList() {
        /*
        DESC: Print the graph as an edge list.
        */
        for (int i = 0; i < n_nodes; i++) {
            for (int j = i + 1; j < n_nodes; j++)
                if (costs[i][j] != INT_MAX)
                    cout << i << " " << j << " " << costs[i][j] << "\n";
        }
    }

    int getCost(int i, int j) {return costs[i][j];}
    int getNumNodes() {return n_nodes;}
    void setCost(int i, int j, int g) {costs[i][j] = costs[j][i] = g; return;}

    vector<int> getNeighbours(int i) {
        /*
        DESC: Returns the neighbours of a given node. 

        INPUTS:
            int i: node.
        
        OUTPUTS:
            vector<int> neighbours: All neighbours of node i. 
        */
        vector<int> neighbours;

        for(int j = 0; j < n_nodes; j++)
            if (conn_matrix[i][j] == true)
                neighbours.push_back(j);
        
        return neighbours;
    }
};

typedef pair<int, int> Pair;

class PriorityQueue {
    /*
    DESC: Implement the priority queue to be used for expanding the closest nodes.
    */
    priority_queue<Pair> pq;
    unordered_set<int> current;

public:
    PriorityQueue() {}

    void push(int node, int priority) {
        /*
        DESC: Push into the heap. C++ maintains a maxheap by default, with the priority being the first element.

        INPUTS:
            int node: node.
            int priority: priority.
        */
        pq.push(make_pair(-priority, node)); 
        current.insert(node); // Add the node to a set to facilitate PriorityQueue::contains().
    }

    void changePriority(int node, int priority) {
        /*
        DESC: Changes the priority of a given node.

        INPUTS:
            int node: node.
            int priority: priority.
        */
        priority_queue<Pair> temp;

        // Pop from the heap till the node is found, then push with modified priority.
        while(!pq.empty()) {
            if (pq.top().second == node) {
                pq.pop();
                pq.push(make_pair(-priority, node));
                break;
            }
            temp.push(pq.top());
            pq.pop();            
        }

        // Push back into the heap.
        while (!temp.empty()) {
            pq.push(temp.top());
            temp.pop();
        }
    }
    
    Pair top() {return make_pair(pq.top().second, -pq.top().first);}
    void pop() {int node = pq.top().second; pq.pop(); current.erase(node);}
    int size() {return pq.size();}
    bool empty() {return pq.empty();}
    bool contains(int node) {return current.find(node) != current.end();}
};

class ShortestPath {
    /*
    DESC: Implements the shortest path algorithm and processes the data to compute paths anhd distances.
    */
    const int start;
    const int goal;
    Graph G;
    
    vector<Node> nodes;
    vector<vector<int> > paths;
    unordered_set<int> CLOSED;
    PriorityQueue OPEN;
    double avg;
public:
    ShortestPath(int source_node, int target_node, Graph& graph) 
        : start(source_node), goal(target_node), G(graph), paths(vector<vector<int> >(graph.getNumNodes())){
            for (int i = 0; i < graph.getNumNodes(); i++)
                nodes.push_back(Node(i, (i == source_node)? 0 : INT_MAX));
            // G.printGraphAsList();
            
            runDijkstra();
        }
    
    void runDijkstra() {
        /*
        DESC: Main function calling other functions.
        */
        dijkstra();
        computePaths();
        computeAverageDist();
        printResults();
    }

    void dijkstra() {
        /*
        DESC: Runs dijkstra's algorithm on the given graph and start/goal nodes.
        */
        OPEN.push(start, 0);
        
        while (!OPEN.empty()) {
            
            int node_to_expand = OPEN.top().first;
            int cost_from_start = OPEN.top().second;
            OPEN.pop();
            CLOSED.insert(node_to_expand);
            
            vector<int> neighbours = G.getNeighbours(node_to_expand);
            for (int neighbour : neighbours) {
                // Shortest path start -> neighbour already found if it is CLOSED.
                if (CLOSED.find(neighbour) != CLOSED.end()) continue;
                
                // Check if current cost to neighbour (start -> node_to_expand -> neighbour) 
                // is better than the existing cost (start -> neighbour)
                bool cost_changed = false;
                int g = cost_from_start + G.getCost(node_to_expand, neighbour);
                if (g < nodes[neighbour].getCostFromStart()) {
                    nodes[neighbour].setCostFromStart(g);           // update cost
                    nodes[neighbour].setPrevNode(node_to_expand);   // update parent
                    cost_changed = true;
                };             
                
                // If neighbour is not in OPEN, then add it. If it IS in OPEN, 
                // then update priority only if it has been changed. 
                // This would save us unnecessary push and pop from heap.
                if (OPEN.contains(neighbour)) {
                    if (cost_changed)
                        OPEN.changePriority(neighbour, nodes[neighbour].getCostFromStart());
                }
                else
                    OPEN.push(neighbour, nodes[neighbour].getCostFromStart());
            }
        }
        return;
    }

    void computePaths() {
        /*
        DESC: Compute paths by backtracking the previous nodes within each node.
        */
        for (int i = 0; i < G.getNumNodes(); i++) {
            int prev_node = i;
            stack<int> path;
            
            while(prev_node != -1) {
                path.push(prev_node);
                prev_node = nodes[prev_node].getPrevNode();
            }
            while (!path.empty()) {
                paths[i].push_back(path.top());
                path.pop();
            }
        } 
    }

    double computeAverageDist() {
        /*
        DESC: Return the average distance between start and all other nodes.

        OUTPUTS:
            double avg: Average distance
        */
        int count = 0;
        for (int i = 0; i < G.getNumNodes(); i++)
            if (i != start && nodes[i].getCostFromStart() < INT_MAX) // Skip the disconnected and start node
                avg += static_cast<double>(nodes[i].getCostFromStart() - avg) / ++count;

        return avg;
    }

    void printResults() {
        /*
        DESC: Print all the results.
                1. Shortest distances from start -> each node
                2. Paths from start -> each node 
                3. Is path found from start to goal? (Yes/No)
                4. Average distance from start to any other node in the graph.
        */
        
        // 1. Shortest distances from start -> each node
        // 2. Paths from start -> each node 
        cout << '\n' << string(20, '-') << "Computed paths" << string(20, '-') << '\n';

        for (int i = 0; i < G.getNumNodes(); i++){
            cout << "dist(" << setw(2) << left << start << " -> " << setw(2) << right << i << ") = "
                 << setw(10) << left << nodes[i].getCostFromStart() << ": ";
            for(int j = 0; j < paths[i].size(); j++) {
                cout << setw(2) << right << paths[i][j];
                if (j < paths[i].size() - 1) cout << " -> ";
            }
            cout << "\n";
        }

        // 3. Is path found from start to goal? (Yes/No)
        // 4. Average distance from start to any other node in the graph.
        cout << "\nPath found from " << start << " to " << goal << "? "
             << ((nodes[goal].getCostFromStart() < INT_MAX)? "Yes." : "No.")
             << " Average distance between two nodes is " << avg << ".\n";
        
    }
};

int main(int argc, char **argv) {
    srand(time(0));     // Output is provided with srand(7);
    
    Graph graph(50, 0.2, 1, 10, false);         // Create graph
    ShortestPath shortest_path(1, 27, graph);   // Initialize shortest path
    
    return 0;
}