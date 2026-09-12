class Solution {
public:
 int dfs(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& vis) {
        if(i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size())
            return INT_MAX;
        if(vis[i][j])return INT_MAX;
        if(mat[i][j]==1)return 0;
        vis[i][j]=1;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        int mn=INT_MAX;
        for(int d=0;d<4;d++){
            int val=dfs(mat,i+dx[d],j+dy[d],vis);
            if(val!=INT_MAX)mn=min(1+val,mn);
        }
        vis[i][j]=0;
        return mn;

    }
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
       int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];

                if(ni >= 0 && nj >= 0 && ni < n && nj < m 
                   && ans[ni][nj] == -1) {
                    
                    ans[ni][nj] = ans[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }

        return ans;
    }
};