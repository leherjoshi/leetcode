class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
         unordered_map<int,int>mp;
         priority_queue<int, vector<int>, greater<int>> pq;
         for(int x:arr)pq.push(x);
         int j=1;
         for(int i=0;i<arr.size();i++){
            if(mp[pq.top()]!=0){
                pq.pop();
                continue;
            }
            mp[pq.top()]=j++;
            pq.pop();
         }
         vector<int>ans;
         for(int i=0;i<arr.size();i++){
            ans.push_back(mp[arr[i]]);
            
         }
        return ans;

    }
};