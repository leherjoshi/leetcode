class Solution {
public:
    int dp[31][31][31];

    bool solve(int i, int j, int len, string &s1, string &s2) {
        if(len == 1)
            return s1[i] == s2[j];

        if(dp[i][j][len] != -1)
            return dp[i][j][len];

        if(s1.substr(i, len) == s2.substr(j, len))
            return dp[i][j][len] = true;

        return split(i, j, len, s1, s2, 1);
    }

    bool split(int i, int j, int len, string &s1, string &s2, int k) {
        if(k == len)
            return dp[i][j][len] = false;

        // No swap
        if(solve(i, j, k, s1, s2) &&
           solve(i+k, j+k, len-k, s1, s2))
            return dp[i][j][len] = true;

        // Swap
        if(solve(i, j+len-k, k, s1, s2) &&
           solve(i+k, j, len-k, s1, s2))
            return dp[i][j][len] = true;

        return split(i, j, len, s1, s2, k+1);
    }

    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, s1.size(), s1, s2);
    }
};