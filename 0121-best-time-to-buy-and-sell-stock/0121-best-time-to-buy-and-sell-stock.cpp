class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0;
        int sell=prices[0];

        for(int i=0;i<prices.size();i++){
            sell=min(sell,prices[i]);
            buy=max(buy,prices[i]-sell);
        }
        return buy;
    }
};