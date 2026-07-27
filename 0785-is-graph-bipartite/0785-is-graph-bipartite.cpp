class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>&col){
        
        for(int nei:graph[node]){
            if(col[nei]==-1){
                col[nei]=1-col[node];
                 if(!dfs(nei,graph,col))return false;
            }else if(col[nei]==col[node])return false;

        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>col(n,-1);
        for(int i=0;i<graph.size();i++){
            if(col[i]==-1){
                col[i]=0;
                if(!dfs(i,graph,col))return false;
            }
        }
       return true;
    }
};