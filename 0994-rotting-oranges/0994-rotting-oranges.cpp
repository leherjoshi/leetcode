class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;

        queue<pair<int,pair<int,int>>> q;

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({0, {i,j}});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time_max = 0;
        int rotton = 0;

        while(!q.empty()) {
            auto [t, cell] = q.front();
            q.pop();

            time_max = max(t, time_max);

            int row = cell.first;
            int col = cell.second;

            int dx[] = {1,-1,0,0};
            int dy[] = {0,0,-1,1};

            for(int k = 0; k < 4; k++) {
                int nx = row + dx[k];
                int ny = col + dy[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m 
                   && grid[nx][ny] == 1) {

                    rotton++;
                    grid[nx][ny] = 2;

                    q.push({t+1, {nx,ny}});
                }
            }
        }

        return (rotton == fresh) ? time_max : -1;
    }
};