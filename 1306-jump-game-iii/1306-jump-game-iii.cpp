class Solution {
public:
    bool solve(int i,vector<int>&arr,vector<int>&vis){
        if(i<0||i>=arr.size()||vis[i]==1)return false;

        if(arr[i]==0)return true;
        
        vis[i]=1;
        return solve(i+arr[i],arr,vis)||solve(i-arr[i],arr,vis);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size(),0);
        return solve(start,arr,vis);
    }
};