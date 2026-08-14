class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
     
      queue<pair<int, pair<int,int>>> q;


        int n=grid.size();
        int m=grid[0].size();
       vector<vector<int>>vis=grid;
        int cnt=0;
   
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    cnt++;                    
                }else if(grid[i][j]==2){
                    q.push({0,{i,j}});
                   
                }
            }
        }
        int tm=0;
        while(!q.empty()){
            auto [t,cell]=q.front();
            q.pop();

            int row=cell.first;
            int col=cell.second;

            tm=max(tm,t);
            

            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};

            for(int dir=0;dir<4;dir++){
                int nx=row+dx[dir];
                int ny=col+dy[dir];

                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    if(vis[nx][ny]==1){
                        vis[nx][ny]=2;
                        q.push({t+1,{nx,ny}});
                        cnt--;
                    }
                }
            }                        
        }        
        return cnt>0?-1:tm;

    }
};