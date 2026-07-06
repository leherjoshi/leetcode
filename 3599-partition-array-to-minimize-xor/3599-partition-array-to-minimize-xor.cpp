class Solution {
public:
    int n;
    const int INF = INT_MAX;

    int solve(int i, vector<int>& nums, int k, vector<vector<int>>& dp) {
        // k parts must exactly cover nums[i..n-1]
        if (k == 0) return (i == n) ? 0 : INF;
        if (i == n) return INF;              // ran out of elements but still need parts
        if (dp[i][k] != -1) return dp[i][k];

        int best = INF;
        int curXor = 0;
        // j is the end index of the CURRENT subarray nums[i..j]
        // must leave at least (k-1) elements for the remaining k-1 parts
        for (int j = i; j <= n - k; j++) {
            curXor ^= nums[j];
            int rest = solve(j + 1, nums, k - 1, dp);
            if (rest != INF) {
                best = min(best, max(curXor, rest));
            }
        }
        return dp[i][k] = best;
    }

    int minXor(vector<int>& nums, int k) {
        n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(0, nums, k, dp);
    }
};