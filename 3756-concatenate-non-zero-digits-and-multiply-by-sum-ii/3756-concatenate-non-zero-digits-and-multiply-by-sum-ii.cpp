class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // Powers of 10
        vector<long long> pw(n + 1);
        pw[0] = 1;
        for (int i = 1; i <= n; i++) {
            pw[i] = (pw[i - 1] * 10) % MOD;
        }

        // Prefix arrays
        vector<int> sum(n + 1, 0);
        vector<long long> x(n + 1, 0);
        vector<int> cnt(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            sum[i + 1] = sum[i] + d;

            if (d > 0) {
                x[i + 1] = (x[i] * 10 + d) % MOD;
                cnt[i + 1] = cnt[i] + 1;
            } else {
                x[i + 1] = x[i];
                cnt[i + 1] = cnt[i];
            }
        }

        int m = queries.size();
        vector<int> res(m);

        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            int len = cnt[r + 1] - cnt[l];

            long long val =
                (x[r + 1] - (x[l] * pw[len]) % MOD + MOD) % MOD;

            int digitSum = sum[r + 1] - sum[l];

            res[i] = (val * digitSum) % MOD;
        }

        return res;
    }
};