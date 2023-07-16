#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<string>
#include<limits>

using namespace std;

class Graph {
    /*
    DESC: Graph class to create and process the graph.
    */
    int n_nodes;
    const double density;
    const int DIST_MIN, DIST_MAX;
    vector<vector<bool> > conn_matrix;
    vector<vector<int> > costs;
    
    double prob() {return static_cast<double>(rand()) / RAND_MAX;}
    
    void createRandGraph() {
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
    Graph(string s, bool print_graph = false): density(-1), DIST_MIN(-1), DIST_MAX(-1) {
        ifstream inputFile(s);
        if (inputFile.is_open()) {
            inputFile >> n_nodes; // Read the number of lines
            
            conn_matrix = vector<vector<bool> > (n_nodes, vector<bool> (n_nodes, false));
            costs = vector<vector<int> > (n_nodes, vector<int> (n_nodes, INT_MAX));

            int source, target, cost;
            
            // Construct the connectivity and cost matrices.
            while (inputFile >> source >> target >> cost) {
                conn_matrix[source][target] = conn_matrix[target][source] = true;
                costs[source][target] = costs[target][source] = cost;
            }
            
            // Set the loop costs of Node i -> i = 0
            for (int i = 0; i < n_nodes; i++) costs[i][i] = 0;
                    
            inputFile.close();
        }
            
        if (print_graph) {
            printMatrix(conn_matrix);
            printMatrix(costs);
        }
    }

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
        
        createRandGraph();

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

#endif // GRAPH_H