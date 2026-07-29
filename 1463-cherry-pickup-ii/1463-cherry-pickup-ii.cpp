class Solution {
public:
    int n,m;

    int solve(vector<vector<int>>& grid,int r,int c1,int c2, vector<vector<vector<int>>>&dp){
        if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
            return -1e9;
     
     if(r==n-1){
        if(c1!=c2){
            return grid[r][c1]+grid[r][c2];
        }
        return grid[r][c1];
     }

       if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
    
    int cherries=0;
        if(c1!=c2){
            cherries= grid[r][c1]+grid[r][c2];
        }
        else cherries= grid[r][c1];

        int best=0;

       for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                best=max(best,solve(grid,r+1,c1+d1,c2+d2,dp));
            }
       }

        return dp[r][c1][c2]=best+cherries;
    }
    

    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(grid,0,0,m-1,dp);
    }
};