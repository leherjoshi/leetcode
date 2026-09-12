class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[]={0,0,1,-1};
        int dy[]={-1,1,0,0};

        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            

                for(int d=0;d<4;d++){
                    int ni=dx[d]+i;
                    int nj=dy[d]+j;
                    
                    if(ni>=0 && nj>=0 &&ni<n && nj<m && ans[ni][nj]==INT_MAX){
                        ans[ni][nj]=min(ans[ni][nj],1+ans[i][j]);
                        q.push({ni,nj});
                    }
                }
        }
        return ans;
    }
};