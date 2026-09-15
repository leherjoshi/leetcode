class Solution {
public:
    bool solve(vector<int>& stones, int i, int last, vector<vector<int>>& dp) {
        if(i == stones.size() - 1)
            return true;

        if(dp[i][last] != -1)
            return dp[i][last];

        for(int d = -1; d < 2; d++) {
            int jump = last + d;

            if(jump <= 0)
                continue;

            int nextpos = stones[i] + jump;

            int low = i + 1;
            int high = stones.size() - 1;

            while(low <= high) {
                int mid = (low + high) / 2;

                if(stones[mid] == nextpos) {
                    if(solve(stones, mid, jump, dp))
                        return dp[i][last] = true;

                    break;
                }
                else if(stones[mid] < nextpos) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return dp[i][last] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if(n < 2 || stones[1] != 1)
            return false;

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(stones, 0, 0, dp);
    }
};