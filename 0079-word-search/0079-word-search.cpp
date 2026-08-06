class Solution {
public:
    int n, m;

    bool dfs(int i, int j, int idx, vector<vector<char>>& board,
             string &word, vector<vector<int>>& vis) {

        if (board[i][j] != word[idx])
            return false;

        if (idx == word.size() - 1)
            return true;

        vis[i][j] = 1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                !vis[ni][nj]) {

                if (dfs(ni, nj, idx + 1, board, word, vis))
                    return true;
            }
        }

        vis[i][j] = 0;   // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, 0, board, word, vis))
                    return true;
            }
        }

        return false;
    }
};