class Solution {
public:

    bool solve(int i, int j, string &s, string &p) {

        // Both exhausted
        if(i == s.size() && j == p.size())
            return true;

        // Pattern exhausted
        if(j == p.size())
            return false;

        bool match = (i < s.size() &&
                     (s[i] == p[j] || p[j] == '.'));

        // If next character is *
        if(j+1 < p.size() && p[j+1] == '*') {

            // Choice 1: Zero occurrences
            bool zero = solve(i, j+2, s, p);

            // Choice 2: One or more occurrences
            bool take = false;

            if(match) {
                take = solve(i+1, j, s, p);
            }

            return zero || take;
        }

        // Normal character or '.'
        if(match) {
            return solve(i+1, j+1, s, p);
        }

        return false;
    }

    bool isMatch(string s, string p) {
        return solve(0, 0, s, p);
    }
};