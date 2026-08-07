class Solution {
public:
    int solve(int i, int deleted, vector<int>& arr,
              vector<vector<int>>& dp) {

        if(i == 0) {
            return arr[0];
        }

        if(dp[i][deleted] != -1e9)
            return dp[i][deleted];

        // Take arr[i]
        int take = arr[i] + solve(i-1, deleted, arr, dp);

        // Start new subarray from arr[i]
        take = max(take, arr[i]);

        int del = -1e9;

        // Delete arr[i]
        if(deleted == 0) {
            del = solve(i-1, 1, arr, dp);
        }

        return dp[i][deleted] = max(take, del);
    }

    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(2, -1e9));

        int ans = -1e9;

        for(int i = 0; i < n; i++) {
            ans = max(ans, solve(i, 0, arr, dp));
            ans = max(ans, solve(i, 1, arr, dp));
        }

        return ans;
    }
};