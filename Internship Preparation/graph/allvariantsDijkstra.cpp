// single_source.cpp
#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

typedef pair<int, int> pii;

void dijkstra_single_source(vector<vector<pii>>& graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INF);
    priority_queue<pii, vector<pii>, greater<>> pq;

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        // Skip if we've already found a better path
        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < V; ++i)
        cout << "Distance from " << src << " to " << i << " is " << dist[i] << endl;
}

// single_destination.cpp
void dijkstra_single_destination(vector<vector<pii>>& graph, int dest) {
    int V = graph.size();
    vector<vector<pii>> reversed_graph(V);
    for (int u = 0; u < V; ++u) {
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            reversed_graph[v].emplace_back(u, w);
        }
    }
    dijkstra_single_source(reversed_graph, dest);
}

// single_pair.cpp
int dijkstra_single_pair(vector<vector<pii>>& graph, int src, int dest) {
    int V = graph.size();
    vector<int> dist(V, INF);
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        // Skip if we've already found a better path
        if (d > dist[u]) continue;
        
        // Don't early terminate when reaching dest
        // Process all neighbors to ensure shortest path
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[dest];
}

// all_pairs.cpp
vector<vector<int>> dijkstra_all_pairs(vector<vector<pii>>& graph) {
    int V = graph.size();
    vector<vector<int>> all_dist(V, vector<int>(V, INF));
    for (int u = 0; u < V; ++u) {
        vector<int> dist(V, INF);
        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.push({0, u});
        dist[u] = 0;

        while (!pq.empty()) {
            int curr = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            // Skip if we've already found a better path
            if (d > dist[curr]) continue;

            for (auto& edge : graph[curr]) {
                int v = edge.first;
                int w = edge.second;
                if (dist[v] > dist[curr] + w) {
                    dist[v] = dist[curr] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        all_dist[u] = dist;
    }
    return all_dist;
}

int main() {
    int V = 5;
    vector<vector<pii>> graph(V);

    // Sample weighted directed graph
    graph[0].emplace_back(1, 10);
    graph[0].emplace_back(4, 5);
    graph[1].emplace_back(2, 1);
    graph[1].emplace_back(4, 2);
    graph[2].emplace_back(3, 4);
    graph[3].emplace_back(0, 7);
    graph[3].emplace_back(2, 6);
    graph[4].emplace_back(1, 3);
    graph[4].emplace_back(2, 9);
    graph[4].emplace_back(3, 2);

    cout << "\nSingle-Source Shortest Paths from node 0:\n";
    dijkstra_single_source(graph, 0);

    cout << "\nSingle-Destination Shortest Paths to node 3:\n";
    dijkstra_single_destination(graph, 3);

    cout << "\nSingle-Pair Shortest Path from 0 to 3: ";
    cout << dijkstra_single_pair(graph, 0, 3) << endl;

    cout << "\nAll-Pairs Shortest Paths:\n";
    auto all = dijkstra_all_pairs(graph);
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << "From " << i << " to " << j << " = ";
            if (all[i][j] == INF)
                cout << "INF" << endl;
            else
                cout << all[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}
