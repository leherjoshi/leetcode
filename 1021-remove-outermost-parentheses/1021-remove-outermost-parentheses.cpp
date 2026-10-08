class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string res;

        for (char c : s) {
            if (c == '(') {
                if (count > 0) res += c;
                count++;
            } else {
                count--;
                if (count > 0) res += c;
            }
        }

        return res;
    }
};