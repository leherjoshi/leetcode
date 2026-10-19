class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        // full[v]   = best path sum going down from v (with v and the last node)
        // noLeaf[v] = best path sum going down from v (with v, but without the last node)
        vector<long long> full(n), noLeaf(n);
        for (int i = 0; i < n; i++) {
            full[i] = price[i];
            noLeaf[i] = 0;
        }

        // iterative DFS to get an order and parent of each node
        vector<int> parent(n, -1), order;
        order.reserve(n);
        vector<int> st;
        st.push_back(0);
        parent[0] = -1;
        vector<bool> seen(n, false);
        seen[0] = true;
        while (!st.empty()) {
            int v = st.back();
            st.pop_back();
            order.push_back(v);
            for (int u : g[v]) {
                if (!seen[u]) {
                    seen[u] = true;
                    parent[u] = v;
                    st.push_back(u);
                }
            }
        }

        long long ans = 0;

        // process nodes from bottom to top
        for (int i = n - 1; i >= 0; i--) {
            int v = order[i];
            for (int u : g[v]) {
                if (u == parent[v]) continue;  // only children

                // join the current best of v with child u
                ans = max(ans, full[v] + noLeaf[u]);
                ans = max(ans, noLeaf[v] + full[u]);

                // update the best path going down from v
                full[v] = max(full[v], full[u] + price[v]);
                noLeaf[v] = max(noLeaf[v], noLeaf[u] + price[v]);
            }
        }
        return ans;
    }
};