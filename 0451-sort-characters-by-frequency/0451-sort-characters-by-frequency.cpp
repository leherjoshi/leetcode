class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto &[c,f]:mp){
            pq.push({f,c});
        }
        string ans="";
        while(!pq.empty()){
        auto [f,c]=pq.top();pq.pop();
            ans+=string(f,c);
        }
        return ans;
    }
};