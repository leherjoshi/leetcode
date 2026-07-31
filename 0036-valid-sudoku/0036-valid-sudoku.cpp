class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
            unordered_map<int,int>mp;
            unordered_map<int,int>mp2;
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                mp[board[i][j]]++;
                if(mp[board[i][j]]>=2)return false;
                }
                if(board[j][i] != '.'){
                mp2[board[j][i]]++;
                if(mp2[board[j][i]]>=2)return false;
                }
            }

        }
       for(int k=0;k<9;k++){
        unordered_map<int,int>mp3;
        int row=(k/3)*3;
        int col=(k%3)*3;
         for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(board[j][i] != '.'){
                mp3[board[j][i]]++;
                if(mp3[board[j][i]]>=2)return false;
                }
            }
         }
       }
        return true;
    }
};