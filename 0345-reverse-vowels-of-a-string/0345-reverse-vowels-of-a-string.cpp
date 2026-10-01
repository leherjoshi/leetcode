class Solution {
public:
    bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' ||
               c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {
        vector<char> ch;

        for (int i = 0; i < s.size(); i++) {
            if (isvowel(s[i]))
                ch.push_back(s[i]);
        }

        reverse(ch.begin(), ch.end());

        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            if (isvowel(s[i])) {
                s[i] = ch[j++];
            }
        }

        return s;
    }
};