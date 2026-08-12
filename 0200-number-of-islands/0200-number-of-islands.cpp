class Solution {
public:

    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>& vis){
        int n=grid.size();
        if(r<0||c<0||r>=n||c>=grid[0].size()||vis[r][c]!=-1||grid[r][c]!='1'){
            return ;
        }
        vis[r][c]=1;
        dfs(r+1,c,grid,vis);
         dfs(r,c+1,grid,vis);
          dfs(r-1,c,grid,vis);
           dfs(r,c-1,grid,vis);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),-1));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j]==-1&&grid[i][j]=='1'){
                 dfs(i,j,grid,vis);
                   ans++;
                }
            }
        }
        return ans;
    }
};