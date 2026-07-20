class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
    int n=grid.size();
    int m=grid[0].size();

    for(int l=0;l<k;l++){
        vector<vector<int>>nw=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    
                    if(j==m-1){
                       nw[(i + 1)%n][0] = grid[i][j];
                    }
                    else {
                        // Move to next column
                        nw[i][j + 1] = grid[i][j];
                    }
                    
                }
            }
            grid=nw;
        }
        return grid;
        
    }
};