class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        int odd = 0;
        int left = 0;
        int leftEven = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] % 2 == 1) {
                odd++;
            }

            // More than k odds
            if (odd > k) {
                while (nums[left] % 2 == 0) {
                    left++;
                }

                left++;          // remove first odd
                odd--;
                leftEven = 0;
            }

            // Count even numbers before the first odd
            if (odd == k) {
                while (left <= right && nums[left] % 2 == 0) {
                    leftEven++;
                    left++;
                }

                ans += leftEven + 1;
            }
        }

        return ans;
    }
};