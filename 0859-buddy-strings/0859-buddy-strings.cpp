class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;

        // If both strings are already equal
        if (s == goal) {
            vector<int> freq(26, 0);
            for (char c : s) {
                freq[c - 'a']++;
                if (freq[c - 'a'] > 1) return true;
            }
            return false;
        }

        int mismatch = 0;
        char s1, s2, g1, g2;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                mismatch++;

                if (mismatch == 1) {
                    s1 = s[i];
                    g1 = goal[i];
                }
                else if (mismatch == 2) {
                    s2 = s[i];
                    g2 = goal[i];
                }
                else {
                    return false;
                }
            }
        }

        if (mismatch != 2) return false;

        return (s1 == g2 && s2 == g1);
    }
};