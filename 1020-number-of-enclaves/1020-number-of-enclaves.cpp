class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        // Put all boundary land cells into queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 &&
                   (i == 0 || i == n-1 || j == 0 || j == m-1)) {
                    
                    grid[i][j] = 2;
                    q.push({i, j});
                }
            }
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        // BFS
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(int idx = 0; idx < 4; idx++) {
                int nx = i + dx[idx];
                int ny = j + dy[idx];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m &&
                   grid[nx][ny] == 1) {
                    
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }

        // Remaining 1s are enclaves
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};