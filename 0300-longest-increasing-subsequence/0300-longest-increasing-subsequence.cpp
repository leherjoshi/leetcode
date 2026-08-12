class Solution {
public:
    int solve(int i,int last,vector<int>&nums,vector<vector<int>>&dp){
            if(i==nums.size())return 0;

            if(dp[i][last+1]!=-1)return dp[i][last+1];

            int take=0;
            if(last==-1||nums[i]>nums[last]){
                 take=1+solve(i+1,i,nums,dp);

            }
               

            int nottake=solve(i+1,last,nums,dp);

            return dp[i][last+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);

    }
};