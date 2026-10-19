

class Solution {
public:
    vector<vector<int>> g;
    vector<int> price;
    vector<long long> full, noLeaf;
    long long ans = 0;

    // full[v]   = best path sum going down from v (with v and the last node)
    // noLeaf[v] = best path sum going down from v (with v, but without the last node)
    void dfs(int v, int parent) {
        full[v] = price[v];
        noLeaf[v] = 0;

        for (int u : g[v]) {
            if (u == parent) continue;

            dfs(u, v);  // solve the child first

            // join the current best of v with child u
            ans = max(ans, full[v] + noLeaf[u]);
            ans = max(ans, noLeaf[v] + full[u]);

            // update the best path going down from v
            full[v] = max(full[v], full[u] + price[v]);
            noLeaf[v] = max(noLeaf[v], noLeaf[u] + price[v]);
        }
    }

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        this->price = price;
        g.assign(n, {});
        full.assign(n, 0);
        noLeaf.assign(n, 0);
        ans = 0;

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        return ans;
    }
};