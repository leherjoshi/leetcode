class Solution {
public:

int climbStairs(int n, vector<int>& costs){

    costs.insert(costs.begin(),0);

    vector<int>dp(costs.size()+3,INT_MAX);

    dp[n]=0;

    for(int i=n-1;i>=0;i--){

        if(i+1<=n)
            dp[i]=min(dp[i],
            dp[i+1]+costs[i+1]+1);

        if(i+2<=n)
            dp[i]=min(dp[i],
            dp[i+2]+costs[i+2]+4);

        if(i+3<=n)
            dp[i]=min(dp[i],
            dp[i+3]+costs[i+3]+9);
    }

    return dp[0];
}
};