class Solution {
public:
    long long solve(vector<int>& nums, int k, bool mul) {
        int n = nums.size();

        auto conv = [&](int x) -> long long {
            if (mul) return 1LL * x * k;
            return 1LL * (x / k);   // C++: floor for +ve, ceil for -ve
        };

        const long long NEG = -4e18;

        long long dp0 = NEG; // no operation started
        long long dp1 = NEG; // inside operated segment
        long long dp2 = NEG; // operation finished

        long long ans = NEG;

        for (int x : nums) {
            long long y = conv(x);

            long long ndp2 = max(dp2 + x, dp1 + x);

            long long ndp1 = max({
                y,
                dp0 + y,
                dp1 + y
            });

            long long ndp0 = max(1LL * x, dp0 + x);

            dp0 = ndp0;
            dp1 = ndp1;
            dp2 = ndp2;

            ans = max({ans, dp0, dp1, dp2});
        }

        return ans;
    }

    long long maxSubarraySum(vector<int>& nums, int k) {
        return max(solve(nums, k, true), solve(nums, k, false));
    }
};