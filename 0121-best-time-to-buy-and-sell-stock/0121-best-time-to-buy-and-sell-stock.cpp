class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=INT_MIN;
        int sell=prices[0];
        int n=prices.size();
        for(int i=0;i<n;i++){
            sell=min(sell,prices[i]);
            mx=max(mx,prices[i]-sell);
        }
        return mx;
    }
};