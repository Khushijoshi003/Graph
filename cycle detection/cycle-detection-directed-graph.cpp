#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path) {
        vis[node] = 1;
        path[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, path)) {
                    return true;
                }
            } else if (path[it]) {
                return true;
            }
        }

        path[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        vector<int> vis(V, 0);
        vector<int> path(V, 0);

        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, path)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of directed edges: ";
    cin >> E;

    vector<vector<int>> edges;
    cout << "Enter each edge (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution sol;
    bool hasCycle = sol.isCyclic(V, edges);

    if (hasCycle) {
        cout << "Cycle detected in the directed graph.\n";
    } else {
        cout << "No cycle in the directed graph.\n";
    }

    return 0;
}
