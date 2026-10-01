class Solution {
public:
    int longestSubarray(vector<int>& s) {
        int cnt = 0;
        int prev = 0;
        int maxi = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == 1) {
                cnt++;
            }
            else {
                maxi = max(maxi, prev + cnt);

                prev = cnt;
                cnt = 0;
            }
        }

        maxi = max(maxi, prev + cnt);

        // If there was no zero, we must delete one 1
        if (maxi == s.size())
            return maxi - 1;

        return maxi;
    }
};