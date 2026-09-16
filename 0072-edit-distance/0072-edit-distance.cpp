class Solution {
public:
    // int solve(int i, int j, string word1, string word2,vector<vector<int>>&dp) {
        
    //     if(i == word1.size())
    //         return word2.size() - j;

    //     if(j == word2.size())
    //         return word1.size() - i;

    //     if(dp[i][j] !=-1) return dp[i][j];
    //     int take=INT_MAX;
    //     int replace=INT_MAX;
    //     int del=INT_MAX;
    //     int insert=INT_MAX;
    //     if(word1[i] == word2[j])
    //         take= solve(i + 1, j + 1, word1, word2,dp);
        

        
    //     replace = 1 + solve(i + 1, j + 1, word1, word2,dp);

    //      del = 1 + solve(i + 1, j, word1, word2,dp);

    //     insert = 1 + solve(i, j + 1, word1, word2,dp);
        

    //     return dp[i][j]=min({take,replace, del, insert});
    // }

    int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 0; i <= n; i++)
        dp[i][0] = i;

    for(int j = 0; j <= m; j++)
        dp[0][j] = j;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            if(word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min({
                    dp[i-1][j-1],
                    dp[i-1][j],
                    dp[i][j-1]
                });
            }
        }
    }

    return dp[n][m];
}
};