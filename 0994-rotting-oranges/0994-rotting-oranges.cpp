class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int fresh =0;
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }


        int tm=0;

        while(!q.empty()){
            int t=q.front().first;
            int i= q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            tm=max(tm,t);

            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};

            for(int d=0;d<4;d++){
                int nx=i+dx[d];
                int ny=j+dy[d];
                if(nx>=0 &&nx<n &&ny>=0 &&ny<m && grid[nx][ny]==1){
                    grid[nx][ny]=2;
                    q.push({tm+1,{nx,ny}});
                    fresh--;
                }
            }
        }
        return fresh==0?tm:-1;

    }
};