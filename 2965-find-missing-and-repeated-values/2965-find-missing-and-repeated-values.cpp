class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                mp[grid[i][j]]++;
            }
        }
        vector<int>ans(2,0);
        for(int i=1;i<=(grid.size()*grid.size());i++){
            if(mp[i]==2)ans[0]=i;
            if(mp[i]==0)ans[1]=i;
        }
        return ans;
    }
};