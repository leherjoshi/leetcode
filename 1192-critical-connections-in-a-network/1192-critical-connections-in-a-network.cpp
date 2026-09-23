class Solution {
public:
    vector<vector<int>> adj;
    vector<int> tin, low;
    vector<vector<int>> ans;
    int timer = 0;

    void dfs(int u, int parent) {
        // Time of entering u
        tin[u] = low[u] = timer++;

        for (int v : adj[u]) {

            // Don't consider the edge we used to reach u
            if (v == parent)
                continue;

            // v is already visited -> back edge
            if (tin[v] != -1) {
                low[u] = min(low[u], tin[v]);
            }

            // v is not visited -> DFS
            else {
                dfs(v, u);

                // v's subtree can reach an earlier node
                low[u] = min(low[u], low[v]);

                // No alternate path from v's subtree to u/ancestor
                if (low[v] > tin[u]) {
                    ans.push_back({u, v});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n, vector<vector<int>>& connections) {

        adj.resize(n);
        tin.assign(n, -1);
        low.resize(n);

        // Build undirected graph
        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Start DFS
        for (int i = 0; i < n; i++) {
            if (tin[i] == -1) {
                dfs(i, -1);
            }
        }

        return ans;
    }
};