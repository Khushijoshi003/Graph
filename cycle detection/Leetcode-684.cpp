#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& adj, int parent) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, adj, node)) {
                    return true;
                }
            }
            else if (it != parent) {
                return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);  // 1-based indexing

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<int> vis(n + 1, 0);
            if (dfs(u, vis, adj, -1)) {
                return it;
            }
        }
        return {};
    }
};

int main() {
    int n;
    cout << "Enter number of edges: ";
    cin >> n;

    vector<vector<int>> edges;
    cout << "Enter " << n << " edges (u v):" << endl;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution sol;
    vector<int> result = sol.findRedundantConnection(edges);

    if (!result.empty()) {
        cout << "Redundant Edge: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No redundant edge found." << endl;
    }

    return 0;
}
