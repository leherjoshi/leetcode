class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> ans;

    void dfs(int src, int p) {
        for (auto &[child, wt] : adj[src]) {
            if (child != p) {
                ans[0] += wt;
                dfs(child, src);
            }
        }
    }

    void dfs2(int src, int p) {
        for (auto &[child, wt] : adj[src]) {
            if (child != p) {

                // wt = 0 : src -> child (already correct)
                // wt = 1 : child -> src (needs reversal)

                ans[child] = ans[src] + (wt == 0 ? 1 : -1);

                dfs2(child, src);
            }
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        ans.assign(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], 0});
            adj[e[1]].push_back({e[0], 1});
        }

        // Calculate answer for root 0
        dfs(0, -1);

        // Calculate answers for all other nodes
        dfs2(0, -1);

        return ans;
    }
};