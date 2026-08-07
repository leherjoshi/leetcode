class Solution {
public:
    vector<string> ans;

    void solve(int idx, string expr, long long value,
               long long prev, string &num, int target) {

        if (idx == num.size()) {
            if (value == target)
                ans.push_back(expr);
            return;
        }

        for (int j = idx; j < num.size(); j++) {

            // Skip numbers with leading zeros
            if (j > idx && num[idx] == '0')
                break;

            string part = num.substr(idx, j - idx + 1);
            long long cur = stoll(part);

            if (idx == 0) {
                solve(j + 1, part, cur, cur, num, target);
            } else {
                // +
                solve(j + 1, expr + "+" + part,
                      value + cur,
                      cur,
                      num, target);

                // -
                solve(j + 1, expr + "-" + part,
                      value - cur,
                      -cur,
                      num, target);

                // *
                solve(j + 1, expr + "*" + part,
                      value - prev + prev * cur,
                      prev * cur,
                      num, target);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        ans.clear();
        solve(0, "", 0, 0, num, target);
        return ans;
    }
};