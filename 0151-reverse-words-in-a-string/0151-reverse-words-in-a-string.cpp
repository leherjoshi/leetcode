class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";

        int i = n - 1;

        while (i >= 0) {
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0) break;

            int l = i;
            string words = "";

            while (l >= 0 && s[l] != ' ') {
                words += s[l];
                l--;
            }

            reverse(words.begin(), words.end());
            ans += " " + words;

            i = l;
        }

        if (ans.empty()) return "";
        return ans.substr(1);
    }
};