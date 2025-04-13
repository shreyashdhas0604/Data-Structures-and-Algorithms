#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<bool>&visited,vector<vector<int>>&adj) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor,visited,adj);
        }
    }
}



