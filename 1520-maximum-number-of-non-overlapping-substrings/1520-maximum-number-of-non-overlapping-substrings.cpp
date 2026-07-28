class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);
        for (int i = 0; i < n; i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = max(last[s[i] - 'a'], i);
        }

        vector<pair<int, int>> interval;

        for (int i = 0; i < 26; i++) {
            if (first[i] == n)
                continue;

            int f = first[i];
            int l = last[i];
            bool valid = true;

            for (int k = f; k <= l && valid; k++) {
                char ch = s[k];
                if (first[ch - 'a'] < f) {
                    valid = false;
                    break;
                }
                l = max(l, last[ch - 'a']);
            }
            if (valid)
                interval.push_back({f, l});
        }

        sort(interval.begin(), interval.end(), [&](auto& a, auto& b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        });
        vector<string> ans;
        int end = -1;
        for (auto it : interval) {
            if (it.first > end) {
                ans.push_back(s.substr(it.first, it.second - it.first + 1));
                end = it.second;
            }
        }
        return ans;
    }
};