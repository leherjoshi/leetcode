class Solution {
public:
    void dfs(vector<vector<int>>& adj, int i, vector<int>& vis) {
        vis[i] = 1;
        for (int x : adj[i]) {
            if (!vis[x]) {
                dfs(adj, x, vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // If total cables are less than the minimum needed to connect n computers
        if (connections.size() < n - 1) {
            return -1;
        }

        // Build the adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Count total connected components
        int components = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                dfs(adj, i, vis);
            }
        }

        // To connect 'components' networks, we need exactly 'components - 1' cables
        return components - 1;
    }
};
