class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());

        long long ans = 0;

        // Number of useful multipliers (>1)
        int t = min(k, max(0, mul - 1));

        int cur = mul;

        // Use multiplication on the largest t elements
        for (int i = 0; i < t; i++) {
            ans += 1LL * nums[i] * cur;
            cur--;
        }

        // Add the remaining selected elements normally
        for (int i = t; i < k; i++) {
            ans += nums[i];
        }

        return ans;
    }
};