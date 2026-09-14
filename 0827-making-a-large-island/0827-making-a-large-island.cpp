class Solution {
public:
   
    int n;
    int dfs(int i,int j,vector<vector<int>>&grid,int id){
        grid[i][j]=id;
        int cnt=1;
         int dx[]={1,-1,0,0};
    int dy[]={0,0,-1,1};
        for(int d=0;d<4;d++){
            int nc=i+dx[d];
            int nr=j+dy[d];

            if(nr >= 0 && nc >= 0 && nr < n && nc < n&& grid[nc][nr]==1)
            {
                cnt+=dfs(nc,nr,grid,id);
            }
        }
        return cnt;
            }

    int largestIsland(vector<vector<int>>& grid) {
        int dx[]={1,-1,0,0};
            int dy[]={0,0,-1,1};
        n=grid.size();
        vector<int>key;
        int id=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    key.push_back(dfs(i,j,grid,id++));
                }
            }
        }

        if(key.size()==0)return 1;
        int ans=1;



        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int cnt=1;

                    for(int d=0;d<4;d++){
                        int nc=i+dx[d];
                        int nr=j+dy[d];

                        if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nc][nr]!=0 && key[grid[nc][nr]-2]>0)
                        {
                         cnt+=key[grid[nc][nr]-2];
                            key[grid[nc][nr]-2]*=-1;
                        }
                    
                    }
                    for(int d=0;d<4;d++){
                        int nc=i+dx[d];
                        int nr=j+dy[d];

                        if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nc][nr]!=0 && key[grid[nc][nr]-2]<0)
                        {
                        
                            key[grid[nc][nr]-2]*=-1;
                        }
                    
                    }
                    ans=max(ans,cnt);


                }
            }
        }
        return ans==1?n*n:ans;
    }
};