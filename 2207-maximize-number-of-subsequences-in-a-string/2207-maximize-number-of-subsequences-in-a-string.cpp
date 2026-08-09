class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();

        vector<long long> par0(n, 0);
        vector<long long> par1(n, 0);

        par0[0] = (text[0] == pattern[0]);

        for (int i = 1; i < n; i++) {
            par0[i] = par0[i - 1] + (text[i] == pattern[0]);
        }

        par1[n - 1] = (text[n - 1] == pattern[1]);

        for (int i = n - 2; i >= 0; i--) {
            par1[i] = par1[i + 1] + (text[i] == pattern[1]);
        }

        long long cntp0 = 0;
        long long cntp = 0;

        for (int i = 0; i < n; i++) {

            if (text[i] == pattern[0]) {
                cntp += par1[i] - (text[i] == pattern[1]);
                cntp0++;
            }
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            // Insert pattern[0] before i
            ans = max(ans, cntp + par1[i]);

            // Insert pattern[1] after i
            ans = max(ans, cntp + par0[i]);
        }

        return ans;
    }
};