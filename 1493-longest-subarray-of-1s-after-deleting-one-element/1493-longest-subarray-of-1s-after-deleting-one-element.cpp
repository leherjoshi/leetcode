class Solution {
public:
    int longestSubarray(vector<int>& s) {
        int left = 0;
        int zero = 0;
        int maxi = 0;

        for (int right = 0; right < s.size(); right++) {
            if (s[right] == 0)
                zero++;

            while (zero > 1) {
                if (s[left] == 0)
                    zero--;
                left++;
            }

            maxi = max(maxi, right - left);
        }

        return maxi;
    }
};