class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n,0);
        int sell=prices[0];
        dp[0]=0;
        for(int i=1;i<prices.size();i++){
            if(sell>prices[i])sell=prices[i];
            dp[i]=max(dp[i-1],prices[i]-sell);
        }
       return dp[n-1];
    // int min_prices=prices[0];
    // int profit=0;
    //     for(int i=0;i<n;i++){
    //         if(min_prices>prices[i])min_prices=prices[i];
    //         profit=max(profit,prices[i]-min_prices);
    //     }
    //     return profit;
    }

};