class Solution {
public:
    int n;

    bool solve(vector<int>& stones, int i, int last, vector<vector<int>>& dp) {

        // Reached last stone
        if (i == n - 1)
            return true;

        // Memoization
        if (dp[i][last] != -1)
            return dp[i][last];

        // Try jumps: last-1, last, last+1
        for (int d = -1; d <= 1; d++) {

            int jump = last + d;

            // Jump length must be positive
            if (jump <= 0)
                continue;

            int nextPos = stones[i] + jump;

            // Linear search for the next stone
            for (int j = i + 1; j < n; j++) {

                if (stones[j] == nextPos) {
                    if (solve(stones, j, jump, dp))
                        return dp[i][last] = true;
                }

                // Stones are sorted
                if (stones[j] > nextPos)
                    break;
            }
        }

        return dp[i][last] = false;
    }

    bool canCross(vector<int>& stones) {

        n = stones.size();

        // First jump must be 1
        if (stones[1] != 1)
            return false;

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(stones, 0, 0, dp);
    }
};