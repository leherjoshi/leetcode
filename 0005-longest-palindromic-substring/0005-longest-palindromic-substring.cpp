class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string longest = "";

        for (int center = 0; center < n; ++center) {
            // Odd length palindrome
            int l = center, r = center;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > longest.size()) {
                    longest = s.substr(l, r - l + 1);
                }
                l--; r++;
            }

            // Even length palindrome
            l = center, r = center + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > longest.size()) {
                    longest = s.substr(l, r - l + 1);
                }
                l--; r++;
            }
        }

        return longest;
    }
};
