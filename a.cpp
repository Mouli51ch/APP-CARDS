#include <iostream>
#include<vector> 
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

void topologicalSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj) {
    visited[node] = true;
    for (int neighbour : adj[node]) {
        if (!visited[neighbour])
            topologicalSort(neighbour, visited, s, adj);
    }
    // Important: Push the current node after visiting all its neighbours
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    stack<int> s;

    // Start DFS from each unvisited node
    for (int i = 0; i < v; i++) {
        if (!visited[i])
            topologicalSort(i, visited, s, adj);
    }

    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}