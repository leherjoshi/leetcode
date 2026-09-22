class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {

        vis[i][j] = 1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];

            if(ni >= 0 && ni < grid.size() &&
               nj >= 0 && nj < grid[0].size() &&
               grid[ni][nj] == '1' &&
               !vis[ni][nj]) {

                dfs(ni, nj, grid, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return cnt;
    }
};