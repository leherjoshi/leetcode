class Solution {
public:
    int lcp(const string &a, const string &b) {
        int i = 0;
        while (i < a.size() && i < b.size() && a[i] == b[i])
            i++;
        return i;
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();

        // Edge cases
        if (n == 1) return {0};
        if (n == 2) return {0, 0};

        // adj[i] = LCP(words[i], words[i+1])
        vector<int> adj(n - 1);
        for (int i = 0; i < n - 1; i++)
            adj[i] = lcp(words[i], words[i + 1]);

        // Prefix maximum
        vector<int> pref(n - 1);
        pref[0] = adj[0];
        for (int i = 1; i < n - 1; i++)
            pref[i] = max(pref[i - 1], adj[i]);

        // Suffix maximum
        vector<int> suff(n - 1);
        suff[n - 2] = adj[n - 2];
        for (int i = n - 3; i >= 0; i--)
            suff[i] = max(suff[i + 1], adj[i]);

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int mx = 0;

            // Adjacent pairs completely on the left
            if (i >= 2)
                mx = max(mx, pref[i - 2]);

            // Adjacent pairs completely on the right
            if (i + 1 <= n - 2)
                mx = max(mx, suff[i + 1]);

            // New adjacent pair formed after deleting words[i]
            if (i > 0 && i < n - 1)
                mx = max(mx, lcp(words[i - 1], words[i + 1]));

            ans[i] = mx;
        }

        return ans;
    }
};