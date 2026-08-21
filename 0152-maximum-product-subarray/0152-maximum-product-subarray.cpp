class Solution {
public:
    pair<int,int> solve(int i, vector<int>& nums,
                        vector<pair<int,int>>& dp) {

        if(i == nums.size() - 1)
            return {nums[i], nums[i]};

        if(dp[i].first != INT_MAX)
            return dp[i];

        auto next = solve(i + 1, nums, dp);

        int maxi = max({
            nums[i],
            nums[i] * next.first,
            nums[i] * next.second
        });

        int mini = min({
            nums[i],
            nums[i] * next.first,
            nums[i] * next.second
        });

        return dp[i] = {maxi, mini};
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>> dp(
            n, {INT_MAX, INT_MAX}
        );

        int ans = INT_MIN;

        for(int i = 0; i < n; i++) {
            auto p = solve(i, nums, dp);
            ans = max(ans, p.first);
        }

        return ans;
    }
};