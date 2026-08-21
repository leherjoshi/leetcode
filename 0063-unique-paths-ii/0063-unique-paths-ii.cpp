class Solution {
public:
    int n, m;

    int can(int i, int j, vector<vector<int>>& obs,
            vector<vector<int>>& dp) {

        if(i >= n || j >= m)
            return 0;

        if(obs[i][j] == 1)
            return 0;

        if(i == n-1 && j == m-1)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = can(i, j+1, obs, dp);
        int down = can(i+1, j, obs, dp);

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return can(0, 0, obstacleGrid, dp);
    }
};