class Solution {
public:
    int fun(int i,vector<int>&nums,vector<int>&dp){
        if(i==nums.size()-1)return nums[i];
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int m1=nums[i]+fun(i+2,nums,dp);
        int m2=fun(i+1,nums,dp);
        return dp[i]=max(m1,m2);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
       return fun(0,nums,dp);

    }

};