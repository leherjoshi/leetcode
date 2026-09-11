class Solution {
public:
    void dfs(int i,vector<vector<int>>&adj,vector<int>&vis){
        vis[i]=1;


            for(int c:adj[i]){
                if(!vis[c]){
                    dfs(c,adj,vis);
                }
            }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
       // int m=isConnected[0].size();
        vector<vector<int>>adj(n);

        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
            }
            }
            
        }

        vector<int>vis(n);

        int cnt=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;

    }
};