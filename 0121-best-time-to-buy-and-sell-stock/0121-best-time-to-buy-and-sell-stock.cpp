class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=prices[0];
        int buy=0;

        for(int i=1;i<prices.size();i++){
            sell=min(sell,prices[i]);
            buy=max(prices[i]-sell,buy);
        }
        return buy;
    }
};