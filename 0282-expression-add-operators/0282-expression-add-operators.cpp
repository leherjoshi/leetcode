class Solution {
public:
    void solve(string& num, int idx, long long value, long long prev,
               string expr, int target, vector<string>& ans) {
        int n = num.size();
        if (idx == n) {
            if (value == target) ans.push_back(expr);
            return;
        }
        for (int len = 1; idx + len <= n; len++) {
            string part = num.substr(idx, len);
            if (part.size() > 1 && part[0] == '0') break; // no leading zeros
            long long cur = stoll(part);

            if (idx == 0) {
                solve(num, len, cur, cur, part, target, ans);
            } else {
                solve(num, idx+len, value + cur, cur, expr + "+" + part, target, ans);
                solve(num, idx+len, value - cur, -cur, expr + "-" + part, target, ans);
                solve(num, idx+len, value - prev + prev*cur, prev*cur, expr + "*" + part, target, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.empty()) return ans;
        solve(num, 0, 0, 0, "", target, ans);
        return ans;
    }
};