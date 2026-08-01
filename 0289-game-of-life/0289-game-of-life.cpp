class Solution {
public:
    bool check(vector<vector<int>>& board, int n, int m, int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= m)
            return false;

        // Original state was alive
        return board[x][y] == 1 || board[x][y] == 3;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int cnt = 0;

                for (int d = 0; d < 8; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (check(board, n, m, nx, ny))
                        cnt++;
                }

                if (board[i][j] == 1) {
                    if (cnt < 2 || cnt > 3)
                        board[i][j] = 3;   // alive -> dead
                } else {
                    if (cnt == 3)
                        board[i][j] = 2;   // dead -> alive
                }
            }
        }

        // Finalize states
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 1;
                else if (board[i][j] == 3)
                    board[i][j] = 0;
            }
        }
    }
};