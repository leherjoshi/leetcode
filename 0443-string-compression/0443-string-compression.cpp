class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int k = 0;

        while (i < chars.size()) {
            char c = chars[i];
            int j = i;

            while (j < chars.size() && chars[j] == c)
                j++;

            chars[k++] = c;

            int count = j - i;

            if (count > 1) {
                string s = to_string(count);

                for (char x : s) {
                    chars[k++] = x;
                }
            }

            i = j;
        }

        return k;
    }
};