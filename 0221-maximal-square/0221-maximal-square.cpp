class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>& dp) {
        // base case: first row or first column
        // a '1' here can only ever form a 1x1 square (no room to expand)
        if (i == 0 || j == 0) {
            return dp[i][j] = (matrix[i][j] == '1') ? 1 : 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (matrix[i][j] == '0') {
            return dp[i][j] = 0;
        }

        // take the MIN of the three neighbors (top, left, top-left)
        // because the square is limited by the weakest/smallest neighbor
        int top      = solve(matrix, i-1, j,   dp);
        int left     = solve(matrix, i,   j-1, dp);
        int diagonal = solve(matrix, i-1, j-1, dp);

        // +1 applied ONCE, after taking min
        return dp[i][j] = 1 + min({top, left, diagonal});
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int maxSide = 0;

        // compute dp for EVERY cell, not just one
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxSide = max(maxSide, solve(matrix, i, j, dp));
            }
        }

        // dp stores side length, so square it for area
        return maxSide * maxSide;
    }
};