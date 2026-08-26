class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, cnt = 0;
        string best = "";
        for (int right = 0; right < n; right++) {
            if (s[right] == '1') cnt++;
            while (cnt >= k) {
                while (s[left] == '0') left++;   // trim leading zeros
                string candidate = s.substr(left, right - left + 1);
                if (best.empty() || candidate.size() < best.size() ||
                    (candidate.size() == best.size() && candidate < best)) {
                    best = candidate;
                }
                cnt--;      // drop the leading '1' to search for the next window
                left++;
            }
        }
        return best;
    }
};