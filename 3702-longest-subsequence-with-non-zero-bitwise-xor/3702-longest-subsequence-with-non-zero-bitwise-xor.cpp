class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool nonZero = false;

        for(int i = 0; i < n; i++) {
            xr ^= nums[i];
            if(nums[i] != 0)
                nonZero = true;
        }

        if(xr != 0)
            return n;

        if(nonZero)
            return n - 1;

        return 0;
    }
};