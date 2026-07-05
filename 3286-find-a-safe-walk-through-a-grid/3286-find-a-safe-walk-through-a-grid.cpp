class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        priority_queue<pair<int,pair<int, int>>>pq;
        pq.push({health-grid[0][0],{0, 0}});
        dist[0][0] = grid[0][0];

        while (!pq.empty()) {
            auto [h,cell] = pq.top();
            auto [x,y]=cell;
            pq.pop();

            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, -1, 1};

           
            if(h<dist[x][y])continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                 int nh=h-grid[nx][ny];

                if (nh > dist[nx][ny]) {
                    dist[nx][ny] = nh;
                    pq.push({nh,{nx, ny}});
                }
            }
        }
        return dist[n - 1][m - 1]>0;
    }
};