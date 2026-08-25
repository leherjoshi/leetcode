class Solution {
public:
    long long solve(int i, int last, int n, vector<vector<long long>>& dp) {
        if (i == n) {
            return 1;
        }

        if (dp[i][last + 1] != -1)
            return dp[i][last + 1];

        long long ways = 0;

        if (last == -1) {
            ways = solve(i + 1, 0, n, dp)
                 + solve(i + 1, 1, n, dp)
                 + solve(i + 1, 2, n, dp)
                 + solve(i + 1, 3, n, dp)
                 + solve(i + 1, 4, n, dp);
        }

        if (last == 0) {
            ways = solve(i + 1, 1, n, dp);
        }

        if (last == 1) {
            ways = solve(i + 1, 0, n, dp)
                 + solve(i + 1, 2, n, dp);
        }

        if (last == 2) {
            ways = solve(i + 1, 0, n, dp)
                 + solve(i + 1, 1, n, dp)
                 + solve(i + 1, 3, n, dp)
                 + solve(i + 1, 4, n, dp);
        }

        if (last == 3) {
            ways = solve(i + 1, 2, n, dp)
                 + solve(i + 1, 4, n, dp);
        }

        if (last == 4) {
            ways = solve(i + 1, 0, n, dp);
        }

        return dp[i][last + 1] = ways % 1000000007;
    }

    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(6, -1));
        return solve(0, -1, n, dp);
    }
};