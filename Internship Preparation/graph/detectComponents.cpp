#include <bits/stdc++.h>
using namespace std;

// Function to find the root parent of a node with path compression
int findParent(vector<int>& parent, int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent, parent[x]);
}

// Function to unite two subsets
void unionSets(vector<int>& parent, int x, int y) {
    int px = findParent(parent, x);
    int py = findParent(parent, y);
    if (px != py) {
        parent[px] = py;
    }
}

// Function to find all connected components using DSU
vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
    
    // Initialize each node as its own parent
    vector<int> parent(V);
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    // Union sets using edge list
    for (auto& edge : edges) {
        unionSets(parent, edge[0], edge[1]);
    }

    // Apply path compression for all nodes
    for (int i = 0; i < V; i++) {
        parent[i] = findParent(parent, i);
    }

    // Group nodes by their root parent
    unordered_map<int, vector<int>> resMap;
    for (int i = 0; i < V; i++) {
        resMap[parent[i]].push_back(i);
    }

    // Collect all components into a result vector
    vector<vector<int>> res;
    for (auto& entry : resMap) {
        res.push_back(entry.second);
    }

    return res;
}

int main() {
    int V = 5;

    // Edge list as vector of vectors
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {3, 4}
    };

    // Find connected components using DSU
    vector<vector<int>> res = getComponents(V, edges);
    
    for (const auto& comp : res) {
        for (int node : comp) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}