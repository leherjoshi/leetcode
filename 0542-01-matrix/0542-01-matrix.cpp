class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;

        vector<vector<int>> ans(
            mat.size(),
            vector<int>(mat[0].size(), -1)
        );

        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for(int d = 0; d < 4; d++){
                int nx = i + dx[d];
                int ny = j + dy[d];

                if(nx >= 0 && nx < mat.size() &&
                   ny >= 0 && ny < mat[0].size() &&
                   ans[nx][ny] == -1){

                    ans[nx][ny] = 1 + ans[i][j];
                    q.push({nx,ny});
                }
            }
        }

        return ans;
    }
};