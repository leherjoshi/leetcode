class Solution {
public:
        
    // int solve(int i,int n){
    //     if(i>n)return 0;
    //     if(i==n)return 1;
    //     if(dp[i]!=-1)return dp[i];

    //     return dp[i]=(solve(i+1,n)+solve(i+2,n));
    // }
    int climbStairs(int n) {
        vector<int>dp(n+2,0);
        dp[n]=1;
         dp[n-1]=1;

        for(int i=n-2;i>=0;i--){
            dp[i]=dp[i+1]+dp[i+2];
        }
        return dp[0];
    }
    
};