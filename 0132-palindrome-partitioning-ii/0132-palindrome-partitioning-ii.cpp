class Solution {
public:

    bool isPal(string& s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    int solve(int i, string& s, vector<int>& dp) {

        // Entire remaining string is one palindrome
        if(i == s.size())
            return -1;

        if(dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        // Try every partition
        for(int k = i; k < s.size(); k++) {

            if(isPal(s, i, k)) {

                int cuts = 1 + solve(k + 1, s, dp);

                ans = min(ans, cuts);
            }
        }

        return dp[i] = ans;
    }

    int minCut(string s) {

        vector<int> dp(s.size(), -1);

        return solve(0, s, dp);
    }
};