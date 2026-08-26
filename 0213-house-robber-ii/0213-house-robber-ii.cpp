class Solution {
public:
    int fun(int i,vector<int>&nums,vector<int>&dp){
        // if(i==nums.size()-1)return nums[i];
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int m1=nums[i]+fun(i+2,nums,dp);
        int m2=fun(i+1,nums,dp);
        return dp[i]=max(m1,m2);

    }

 
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return nums[0];
       vector<int>temp1,temp2;
       for(int i=0;i<n;i++){
        if(i!=0)temp1.push_back(nums[i]);
        if(i!=n-1)temp2.push_back(nums[i]);

       } 
       
        vector<int>dp1(n,-1);
        
        vector<int>dp2(n,-1);
       return max({fun(0,temp1,dp1),fun(0,temp2,dp2)});
    }
};