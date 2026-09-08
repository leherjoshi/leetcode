class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 1 && n == 1) return grid[0][0];

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        const int INF = 1e9;

        vector<vector<vector<vector<int>>>> dist(
            m, vector<vector<vector<int>>>(
                n, vector<vector<int>>(4, vector<int>(k + 1, INF))
            )
        );

        
        using State = tuple<int, int, int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        for (int d = 0; d < 4; ++d) {
            int nr = dr[d];
            int nc = dc[d];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                int cost = grid[0][0] + grid[nr][nc];
                dist[nr][nc][d][0] = cost;
                pq.push({cost, nr, nc, d, 0});
            }
        }

        while (!pq.empty()) {
            auto [cost, r, c, d, t] = pq.top();
            pq.pop();

            if (cost > dist[r][c][d][t]) continue;

            if (r == m - 1 && c == n - 1) return cost;

            for (int nd = 0; nd < 4; ++nd) {
                int nr = r + dr[nd];
                int nc = c + dc[nd];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                int nt = t + (nd != d ? 1 : 0);
                if (nt > k) continue;

                int ncost = cost + grid[nr][nc];
                if (ncost < dist[nr][nc][nd][nt]) {
                    dist[nr][nc][nd][nt] = ncost;
                    pq.push({ncost, nr, nc, nd, nt});
                }
            }
        }

        return -1;
    }
};