class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis){
            if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j]!=-1||grid[i][j]=='0')
                return;
            int dx[]={1,-1,0,0};
            int dy[]={0,0,-1,1};
            vis[i][j]=1;
            for(int idx=0;idx<4;idx++){
                int nx=i+dx[idx];
                int ny=j+dy[idx];
                 dfs(nx,ny,grid,vis);
                
            }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i =0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                 if(grid[i][j]=='1'&&vis[i][j]==-1){
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};