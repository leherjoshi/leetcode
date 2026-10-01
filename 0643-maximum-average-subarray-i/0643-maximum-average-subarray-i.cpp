class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int cnt0 = 0;
        int left = 0;
        double ans = INT_MIN;

        for (int right = 0; right < nums.size(); right++) {

            cnt0 += nums[right];

            while (right - left + 1 > k) {
                cnt0 -= nums[left];
                left++;
            }

            if (right - left + 1 == k) {
                ans = max(ans, (double)cnt0 / k);
            }
        }

        return ans;
    }
};