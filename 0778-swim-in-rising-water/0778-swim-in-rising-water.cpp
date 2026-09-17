class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        int n = grid.size();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<vector<int>> height(n, vector<int>(n, INT_MAX));

        pq.push({grid[0][0], {0, 0}});
        height[0][0] = grid[0][0];

        while (!pq.empty()) {

            auto [h, pos] = pq.top();
            pq.pop();

            int i = pos.first;
            int j = pos.second;

            if (vis[i][j])
                continue;

            vis[i][j] = 1;

            for (int d = 0; d < 4; d++) {

                int ni = i + dx[d];
                int nj = j + dy[d];

                if (ni < 0 || nj < 0 || ni >= n || nj >= n)
                    continue;

                // Time required to reach neighbour
                int newHeight = max(h, grid[ni][nj]);

                if (newHeight < height[ni][nj]) {
                    height[ni][nj] = newHeight;

                    pq.push({newHeight, {ni, nj}});
                }
            }
        }

        return height[n-1][n-1];
    }
};