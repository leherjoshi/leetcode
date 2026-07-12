class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0)return {};
        unordered_map<int,int>mp;
        int cnt=1;
        for(int i=0;i<n;i++){
            mp[arr[i]]=-1;
        }
        vector<int>temp=arr;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(mp[arr[i]]==-1){
                mp[arr[i]]=cnt++;
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=mp[temp[i]];
        }
        return ans;
    }
};