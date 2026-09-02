class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        //we have to calculate the min index such that is less than i;

        stack<int>st;
        vector<int>ans(prices.size(),0);
        for(int i=0;i<prices.size();i++){
            while(!st.empty()&&prices[st.top()]>=prices[i]){
                ans[st.top()]=prices[i];
                st.pop();

            }
            st.push(i); 
        }
        for(int i=0;i<prices.size();i++){
            cout<<ans[i]<<" ";
        }
        for(int i=0;i<prices.size();i++){
            prices[i]=prices[i]-ans[i];
        }
        return prices;
    }
};