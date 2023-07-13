/*
Implement Dijkstra's algorithm
C++ for C Programmers: Part A
Week 3
Rishabh Bhattacharya
Jul 12th, 2023


Program description: Create a random graph from given parameters, and use dijkstra's algorithm to compute average of all shortest paths.
*/
#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<queue>
#include<unordered_set>
#include<stack>


using namespace std;

class Node {
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
    const int n_nodes;
    const double density;
    const int DIST_MIN, DIST_MAX;
    vector<vector<bool> > conn_matrix;
    vector<vector<int> > costs;
    
    double prob() {return static_cast<double>(rand()) / RAND_MAX;}
    
    void createGraph() {
        for (int i = 0; i < n_nodes; i++) {
            for (int j = i; j < n_nodes; j++) {
                conn_matrix[i][j] = conn_matrix[j][i] = (i == j)? false : (prob() < density);
                if (i == j) costs[i][j] = costs[j][i] = 0;
                
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
            << "\nCost matrix size: " << costs.size() << " x " << costs[0].size() << endl;
        
        createGraph();

        if (print_graph) {
            printMatrix(conn_matrix);
            printMatrix(costs);
        }
        // cout << string(35, '-') << '\n';
    }
    
    template <typename printable>
    void printMatrix(vector<vector<printable> >& matrix) {
        for (int i = 0; i < n_nodes; i++) {
            for (int j = 0; j < n_nodes; j++)
                cout << setw(10) << right << matrix[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
    }

    void printGraph() {
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
        vector<int> neighbours;

        for(int j = 0; j < n_nodes; j++)
            if (conn_matrix[i][j] == true)
                neighbours.push_back(j);
        
        return neighbours;
    }
};

typedef pair<int, int> Pair;

class PriorityQueue {
    priority_queue<Pair> pq;
    unordered_set<int> current;

public:
    PriorityQueue() {}

    void push(int node, int priority) {pq.push(make_pair(-priority, node)); current.insert(node); return;}

    void changePriority(int node, int priority) {
        priority_queue<Pair> temp;

        while(!pq.empty()) {
            if (pq.top().second == node) {
                pq.pop();
                pq.push(make_pair(-priority, node));
                break;
            }
            temp.push(pq.top());
            pq.pop();            
        }

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
    const int start;
    const int goal;
    Graph G;
    
    vector<Node> nodes;
    vector<vector<int> > paths;
    unordered_set<int> CLOSED;
    PriorityQueue OPEN;
public:
    ShortestPath(int source_node, int target_node, Graph& graph) 
        : start(source_node), goal(target_node), G(graph), paths(vector<vector<int> >(graph.getNumNodes())){
            for (int i = 0; i < graph.getNumNodes(); i++)
                nodes.push_back(Node(i, (i == source_node)? 0 : INT_MAX));
            // G.printGraph();
        }

    bool dijkstra() {
        OPEN.push(start, 0);
        
        while (!OPEN.empty()) {
            
            int node_to_expand = OPEN.top().first;
            int cost_from_start = OPEN.top().second;
            OPEN.pop();
            CLOSED.insert(node_to_expand);
            
            vector<int> neighbours = G.getNeighbours(node_to_expand);
            for (int neighbour : neighbours) {
                if (CLOSED.find(neighbour) != CLOSED.end()) continue;
                
                int g = cost_from_start + G.getCost(node_to_expand, neighbour);
                if (g < nodes[neighbour].getCostFromStart()) {
                    nodes[neighbour].setCostFromStart(g);
                    nodes[neighbour].setPrevNode(node_to_expand);
                };             
                
                if (OPEN.contains(neighbour))
                    OPEN.changePriority(neighbour, nodes[neighbour].getCostFromStart());
                else
                    OPEN.push(neighbour, nodes[neighbour].getCostFromStart());
            }
        }
        computePaths();
        printResults();
        return nodes[goal].getCostFromStart() < INT_MAX;
    }

    void computePaths() {
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
        double avg = 0;
        for (int i = 0; i < G.getNumNodes(); i++)
            avg += static_cast<double>(nodes[i].getCostFromStart() - avg) / (i + 1);

        return avg;
    }

    void printResults() {
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

        // print if successful, and also average distance
    }
};

int main(int argc, char **argv) {
    srand(7);
    
    Graph graph(50, 0.2, 1, 10, false);
    ShortestPath shortest_path(1, 3, graph);
    
    bool path_found = shortest_path.dijkstra();
    cout << "\nPath found: " << (path_found? "Yes" : "No") << endl;
    
    return 0;
}