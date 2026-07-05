class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, int>> pq;
        pq.push({0, 0});
        dist[0][0] = grid[0][0];

        while (!pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();

            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, -1, 1};

           

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                 int w = grid[nx][ny];

                if (dist[nx][ny] > dist[x][y] + w) {
                    dist[nx][ny] = w + dist[x][y];
                    pq.push({nx, ny});
                }
            }
        }
        return dist[n - 1][m - 1]<health;
    }
};