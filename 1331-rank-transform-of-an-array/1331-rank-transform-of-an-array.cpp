class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0)return {};
        vector<int>mp(n);
        for(int i=0;i<n;i++){
            mp[i]=i;
        }
      sort(mp.begin(), mp.end(), [&arr](int a, int b) { 
    return arr[a] < arr[b]; 
});

        vector<int>ans(n);
        ans[mp[0]]=1;
        int rank=1;
        for(int i=1;i<n;i++){
            if(arr[mp[i]] != arr[mp[i-1]])
                rank++;

             ans[mp[i]] = rank;
        }

        return ans;
    }
};