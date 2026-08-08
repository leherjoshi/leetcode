class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>res(temp.size());
        stack<int>st;

        for(int i=0;i<temp.size();i++){
            while(!st.empty()&&temp[st.top()]<temp[i]){
                res[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};