class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, cnt1 = 0;
        string ans = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                cnt1++;

            while (cnt1 > k) {
                if (s[left] == '1')
                    cnt1--;
                left++;
            }

            if (cnt1 == k) {
                while (s[left] == '0')
                    left++;

                string curr = s.substr(left, i - left + 1);

                if (ans == "" || curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};