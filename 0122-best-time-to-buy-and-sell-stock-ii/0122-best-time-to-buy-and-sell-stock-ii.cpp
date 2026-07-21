class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold=-prices[0];
        int free=0;
        

        for(int i=1;i<prices.size();i++){
            int s1=max(free,hold+prices[i]);
            int s2=max(hold,free-prices[i]);
            free=s1;
            hold=s2;
        }
        return free;
    }
};
