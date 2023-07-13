/*
Implement Dijkstra's algorithm
C++ for C Programmers: Part A
Week 3
Rishabh Bhattacharya
Jul 12th, 2023


Program description: Create a linked list using random elements. Use bubble sort to sort the list.
*/
#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<queue>
#include<unordered_set>


using namespace std;

class Node {
    int val;
    int cost_from_start;
    int prev;

public:
    Node(int data = 0, int g = 0, int prev_node = -1): val(data), cost_from_start(g), prev(prev_node) {}
};

class Graph {
    const int n_nodes;
    const double density;
    const int DIST_MIN, DIST_MAX;
    vector<vector<bool> > graph;
    vector<vector<int> > costs;
    
    double prob() {return static_cast<double>(rand()) / RAND_MAX;}
    
    void createGraph() {
        for (int i = 0; i < n_nodes; i++) {
            for (int j = i + 1; j < n_nodes; j++) {
                graph[i][j] = (i == j)? false : graph[j][i] = (prob() < density);
                if (graph[i][j] == true)
                    costs[i][j] = costs[j][i] = rand() % (DIST_MAX - DIST_MIN + 1) + DIST_MIN;
            }
        }
    }

public:
    Graph(int n = 8, 
          double d = 0.5, 
          int dist_min = 1.0, 
          int dist_max = 10.0): 
                                n_nodes(n), 
                                density(d), 
                                DIST_MIN(dist_min), 
                                DIST_MAX(dist_max), 
                                graph(vector<vector<bool> > (n, vector<bool> (n, false))),
                                costs(vector<vector<int> > (n, vector<int> (n, INT_MAX))) {
        const int text_width = 20;
        
        cout << "\nInitialized graph with\n----------------------"
            << setw(text_width) << left << "\nNodes:" <<  n_nodes
            << setw(text_width) << left  << "\nDensity:" << density
            << setw(text_width) << left  << "\nMin. distance:" << DIST_MIN
            << setw(text_width) << left  << "\nMax. distance:" << DIST_MAX
            << "\nConn. matrix size: " << graph.size() << " x " << graph[0].size()
            << "\nCost. matrix size: " << costs.size() << " x " << costs[0].size() << endl;
        
        createGraph();
        printMatrix(graph);
        printMatrix(costs);
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

    void printCostsFromStart() {
        for (int i = 0; i < n_nodes; i++)
            cout << setw(10) << right << costs[0][i] << " ";
        
        cout << "\n";
    }

    int getCost(int i, int j) {return costs[i][j];}

    void setCost(int i, int j, int g) {costs[i][j] = costs[j][i] = g; return;}

    vector<int> getNeighbours(int i) {
        vector<int> neighbours;

        for(int j = 0; j < n_nodes; j++)
            if (graph[i][j] == true)
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
            if (pq.top().first == node) {
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
    int start;
    int goal;
    Graph G;
    unordered_set<int> CLOSED;
    PriorityQueue OPEN;
public:
    ShortestPath(int s, int g) : start(s), goal(g) {}

    bool dijkstra() {
        OPEN.push(start, 0);
        
        while (!OPEN.empty() && CLOSED.find(goal) == CLOSED.end()) {
            
            int node_to_expand = OPEN.top().first;
            int cost_from_start = OPEN.top().second;
            OPEN.pop();
            CLOSED.insert(node_to_expand);
            
            vector<int> neighbours = G.getNeighbours(node_to_expand);
            for (int neighbour : neighbours) {
                if (CLOSED.find(neighbour) != CLOSED.end()) continue;
                
                int g = cost_from_start + G.getCost(node_to_expand, neighbour);
                if (g < G.getCost(start, neighbour)) G.setCost(start, neighbour, g);             
                
                if (OPEN.contains(neighbour))
                    OPEN.changePriority(neighbour, G.getCost(start, neighbour));
                else
                    OPEN.push(neighbour, G.getCost(start, neighbour));
            }
        }

        G.printCostsFromStart();
        return G.getCost(start, goal) < INT_MAX;
    }
};

int main(int argc, char **argv) {
    srand(7);
    
    ShortestPath distance (0, 3);
    bool path_found = distance.dijkstra();
    cout << "Path found: " << (path_found? "Yes" : "No") << endl;
    
    return 0;
}