class Solution {
public:
    bool solve(int i, int j, int alice, int bob, int turn,
               vector<int>& piles) {

        if (i > j)
            return alice > bob;

        if (turn == 0) {

            return solve(i + 1, j, alice + piles[i], bob, 1, piles) ||
                   solve(i, j - 1, alice + piles[j], bob, 1, piles);

        } else {

            return solve(i + 1, j, alice, bob + piles[i], 0, piles) &&
                   solve(i, j - 1, alice, bob + piles[j], 0, piles);
        }
    }

    bool stoneGame(vector<int>& A) {
        int n=A.size();
       vector<int> dp(n);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = A[i];
            for (int j = i + 1; j < n; j++)
                dp[j] = max(A[i] - dp[j], A[j] - dp[j - 1]);
        }

        return dp[n - 1] > 0;
    }
};