class Solution {
public:
    bool isvalid(vector<string>& board, int row, int col, int n){
        for(int i=0;i<row;i++)
            if(board[i][col]=='Q') return false;
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
            if(board[i][j]=='Q') return false;
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
            if(board[i][j]=='Q') return false;
        return true;
    }

    void solve(int i,int n,vector<string>&ans,vector<vector<string>>&res){
        if(i==n){
            res.push_back(ans);
            return;
        }
        for(int j=0;j<n;j++){
            if(isvalid(ans,i,j,n)){
                ans[i][j]='Q';
                solve(i+1,n,ans,res);
                ans[i][j]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> ans(n, string(n,'.'));
        solve(0,n,ans,res);
        return res;
    }
};