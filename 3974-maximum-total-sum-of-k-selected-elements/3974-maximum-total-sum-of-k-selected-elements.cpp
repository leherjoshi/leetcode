class Solution {
public:
    const int mod = 1e9 + 7;
    long long maxSum(vector<int>& nums, int k, int mul) {
       
        sort(nums.begin(), nums.end(), greater<int>());
        long long tot = 0;
        int t=min(k,mul);

       for (int i = 0; i < t && mul>0; i++) {
            tot += 1LL * nums[i] * mul;
            mul--;
        }
       
        for (int i = t; i < k; i++) {
            tot += nums[i];
        }

        return tot;
    }
};