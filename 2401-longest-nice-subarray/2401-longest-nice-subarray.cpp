class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        int mx = 0;
        int bits = 0;

        for(int right = 0; right < nums.size(); right++) {

            while((bits & nums[right]) != 0) {
                bits ^= nums[left];
                left++;
            }

            bits |= nums[right];

            mx = max(mx, right - left + 1);
        }

        return mx;
    }
};