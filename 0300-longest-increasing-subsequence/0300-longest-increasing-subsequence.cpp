class Solution {
public:
    int solve(vector<int>&nums,int i,int last){
        if(i==nums.size())return 0;
        
        int take=0;
        if(last==-1||nums[last]<nums[i]){
            take=1+solve(nums,i+1,i);
        }
        int nottake=solve(nums,i+1,last);

        return max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {

            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}
};