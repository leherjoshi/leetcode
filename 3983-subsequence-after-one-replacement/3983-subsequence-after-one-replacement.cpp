class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        const int INF = m + 1;

        // pre[i] = index in t right after matching s[0..i-1] literally
        vector<int> pre(n + 1, INF);
        pre[0] = 0;
        for (int i = 0; i < n; i++) {
            if (pre[i] == INF) break;
            int j = pre[i];
            while (j < m && t[j] != s[i]) j++;
            pre[i + 1] = j + 1 ;
        }

        // suf[i] = index in t from which s[i..n-1] matches literally (searching backward)
        vector<int> suf(n + 1, -1);
        suf[n] = m;
        for (int i = n - 1; i >= 0; i--) {
            if (suf[i + 1] == -1) break;
            int j = suf[i + 1] - 1;
            while (j >= 0 && t[j] != s[i]) j--;
            suf[i] = (j >= 0) ? j : -1;
        }

        if (pre[n] != INF) return true; // no replacement needed

        for (int k = 0; k < n; k++) {
            if (pre[k] == INF) break;      // s[0..k-1] not even matchable literally
            if (suf[k + 1] == -1) continue; // s[k+1..] not matchable literally
            if (pre[k] < suf[k + 1]) return true; // room for 1 replaced char
        }
        return false;
    }
};