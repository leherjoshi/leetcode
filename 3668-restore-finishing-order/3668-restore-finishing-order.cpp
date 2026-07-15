class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>ans;
        int j=0;
        unordered_map<int,int>mp;
        for(int i:friends){
            mp[i]++;
        }
        
        for(int i=0;i<order.size();i++){
            if(mp.count(order[i])){
                ans.push_back(order[i]);
                
            }
        }
        return ans;
    }
};