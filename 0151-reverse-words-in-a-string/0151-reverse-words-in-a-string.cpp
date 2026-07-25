class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> v;
        string a;

        while (ss >> a) {
            v.push_back(a);
        }

        reverse(v.begin(), v.end());

        string ans;
        for (int i = 0; i < v.size(); i++) {
            ans += v[i];
            if (i != v.size() - 1)
                ans += " ";
        }

        return ans;
    }
};