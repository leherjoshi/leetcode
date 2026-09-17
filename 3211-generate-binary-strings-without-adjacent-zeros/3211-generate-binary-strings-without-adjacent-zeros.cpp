class Solution {
public:
    void solve(int i, int last, int n, vector<string>& ans, string s) {
        if(i == n) {
            ans.push_back(s);
            return;
        }

        // Put 0 only if previous character was 1
        if(last == -1 || last == 1)
            solve(i + 1, 0, n, ans, s + '0');

        // Always allowed to put 1
        solve(i + 1, 1, n, ans, s + '1');
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        solve(0, -1, n, ans, "");
        return ans;
    }
};