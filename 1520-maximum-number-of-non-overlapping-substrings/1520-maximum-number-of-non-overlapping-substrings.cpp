class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        vector<int> first(26, n), last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<vector<int>> g(26), rg(26);

        // Build dependency graph
        for (int c = 0; c < 26; c++) {

            if (last[c] == -1) continue;

            for (int i = first[c]; i <= last[c]; i++) {

                int d = s[i] - 'a';

                if (d != c) {
                    g[c].push_back(d);
                    rg[d].push_back(c);
                }
            }
        }

        vector<int> vis(26, 0);
        stack<int> st;

        function<void(int)> dfs1 = [&](int u) {

            vis[u] = 1;

            for (int v : g[u])
                if (!vis[v])
                    dfs1(v);

            st.push(u);
        };

        for (int i = 0; i < 26; i++)
            if (last[i] != -1 && !vis[i])
                dfs1(i);

        fill(vis.begin(), vis.end(), 0);

        vector<pair<int,int>> intervals;

        function<void(int, vector<int>&)> dfs2 =
        [&](int u, vector<int>& comp) {

            vis[u] = 1;
            comp.push_back(u);

            for (int v : rg[u])
                if (!vis[v])
                    dfs2(v, comp);
        };

        while (!st.empty()) {

            int u = st.top();
            st.pop();

            if (vis[u]) continue;

            vector<int> comp;

            dfs2(u, comp);

            int L = n;
            int R = -1;

            for (int x : comp) {
                L = min(L, first[x]);
                R = max(R, last[x]);
            }

            bool ok = true;

            for (int i = L; i <= R && ok; i++) {

                int ch = s[i] - 'a';

                if (first[ch] < L || last[ch] > R)
                    ok = false;
            }

            if (ok)
                intervals.push_back({L, R});
        }

        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {

                 if (a.second == b.second)
                     return a.first > b.first;

                 return a.second < b.second;
             });

        vector<string> ans;

        int end = -1;

        for (auto &p : intervals) {

            if (p.first > end) {

                ans.push_back(s.substr(p.first, p.second - p.first + 1));

                end = p.second;
            }
        }

        return ans;
    }
};