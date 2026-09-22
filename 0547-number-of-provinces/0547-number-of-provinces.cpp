class Solution {
public:

     void dfs(int i,vector<vector<int>>& adj,vector<int>&vis ){
            vis[i]=1;

            for(int nei:adj[i]){
                if(!vis[nei])dfs(nei,adj,vis);
            }
     }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);

            }
        }
        return cnt;
    }
};