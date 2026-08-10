class Solution {
public:

    vector<vector<pair<int,int>>>adj;
    vector<int>ans;

    void dfs(int node,int parent){
        for (auto &[child, wt] : adj[node]) {
            if (child != parent) {
            ans[0]+=wt;
            dfs(child,node);
            }
        }
    }

    void reroot(int node,int parent){
        for(auto &[child,wt]:adj[node]){
            if(child!=parent){
                ans[child]=ans[node]+(wt==0?1:-1);
                reroot(child,node);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& edges) {
         adj.assign(n,{});
        ans.assign(n,0);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],0});
            adj[e[1]].push_back({e[0],1});
        }
        dfs(0,-1);
        //reroot(0,-1);
        return n-ans[0]-1;
    }
};