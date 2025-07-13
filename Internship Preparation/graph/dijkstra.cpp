#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>
using namespace std;

// Function to construct adjacency 
vector<vector<vector<int>>> constructAdj(vector<vector<int>> 
                             &edges, int V) {
                                 
    // adj[u] = list of {v, wt}
    vector<vector<vector<int>>> adj(V); 

    for (const auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); 
    }
    
    return adj;
}

// Structure to store results of Dijkstra algorithm
struct DijkstraResult {
    vector<int> dist;       // Shortest distances
    vector<int> parent;     // Parent vertices in the shortest path
};

// Function to print the shortest path from source to a given destination
void printPath(const vector<int>& parent, int dest) {
    stack<int> path;
    
    // Push all vertices on path to stack
    for (int v = dest; v != -1; v = parent[v]) {
        path.push(v);
    }
    
    // Print path
    cout << "Path: ";
    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) cout << " -> ";
    }
    cout << endl;
}

// Returns shortest distances and paths from src to all other vertices
DijkstraResult dijkstra(int V, vector<vector<int>> &edges, int src){
    
    // Create adjacency list
    vector<vector<vector<int>>> adj = constructAdj(edges, V);

    // Create a priority queue to store vertices that
    // are being preprocessed.
    priority_queue<vector<int>, vector<vector<int>>, 
                   greater<vector<int>>> pq;

    // Create vectors for distances and parent vertices
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);  // -1 indicates no parent

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push({0, src});
    dist[src] = 0;
    // Source is its own parent
    parent[src] = -1;

    // Looping till priority queue becomes empty (or all
    // distances are not finalized) 
    while (!pq.empty()){
        
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        int u = pq.top()[1];
        pq.pop();

        // Get all adjacent of u.
        for (auto x : adj[u]){
            
            // Get vertex label and weight of current
            // adjacent of u.
            int v = x[0];
            int weight = x[1];

            // If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                // Update parent of v to be u
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return {dist, parent};
}

// Driver program to test methods of graph class
int main(){
    int V = 5;
    int src = 0;

    // edge list format: {u, v, weight}
    vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 8}, {1, 4, 6}, 
                                 {2, 3, 2}, {3, 4, 10}};

    DijkstraResult result = dijkstra(V, edges, src);

    cout << "Shortest distances from source vertex " << src << ":" << endl;
    // Print shortest distances in one line
    cout << "Distances: ";
    for (int i = 0; i < V; i++)
        cout << result.dist[i] << " ";
    cout << endl << endl;
    
    // Print shortest paths from source to each vertex
    cout << "Shortest paths from source vertex " << src << ":" << endl;
    for (int i = 0; i < V; i++) {
        if (i == src) {
            cout << "Vertex " << i << ": Source vertex" << endl;
        } else if (result.dist[i] == INT_MAX) {
            cout << "Vertex " << i << ": No path exists" << endl;
        } else {
            cout << "Vertex " << i << " (Distance = " << result.dist[i] << "): ";
            printPath(result.parent, i);
        }
    }
 
    return 0;
}
