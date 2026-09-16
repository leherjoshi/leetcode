class Solution {
public:
    int solve(int i, int j, string word1, string word2,vector<vector<int>>&dp) {
        
        if(i == word1.size())
            return word2.size() - j;

        if(j == word2.size())
            return word1.size() - i;

        if(dp[i][j] !=-1) return dp[i][j];
        int take=INT_MAX;
        int replace=INT_MAX;
        int del=INT_MAX;
        int insert=INT_MAX;
        if(word1[i] == word2[j])
            take= solve(i + 1, j + 1, word1, word2,dp);
        

        
        replace = 1 + solve(i + 1, j + 1, word1, word2,dp);

         del = 1 + solve(i + 1, j, word1, word2,dp);

        insert = 1 + solve(i, j + 1, word1, word2,dp);
        

        return dp[i][j]=min({take,replace, del, insert});
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return solve(0, 0, word1, word2,dp);
    }
};