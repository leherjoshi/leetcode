class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
       
        int n=grid.size();
         vector<vector<int>> grid2(n,vector<int>(n));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){

                grid2[i][j]=grid[j][i];
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i]==grid2[j])cnt++;
            }
        }
        return cnt;
        
    }
};