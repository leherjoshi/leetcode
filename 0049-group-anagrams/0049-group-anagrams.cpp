class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<string> strs = str;

        for (int i = 0; i < strs.size(); i++) {
            sort(strs[i].begin(), strs[i].end());
        }

        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            mp[strs[i]].push_back(str[i]);
        }

        vector<vector<string>> g;

        for (auto &it : mp) {
            g.push_back(it.second);
        }

        return g;
    }
};