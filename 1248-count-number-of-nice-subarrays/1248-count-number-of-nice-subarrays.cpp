class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        int left = 0;
        int odd = 0;
        int leftEven = 0;

        for (int right = 0; right < n; right++) {

            if (nums[right] % 2 == 1) {
                odd++;
            }

            // We have more than k odds:
            // remove the first odd and everything before it
            if (odd > k) {
                while (odd > k) {
                    if (nums[left] % 2 == 1) {
                        odd--;
                    }
                    left++;
                }

                leftEven = 0;
            }

            // Count even numbers before the first odd
            // inside the current window
            if (odd == k) {
                int temp = left;

                while (temp < right && nums[temp] % 2 == 0) {
                    temp++;
                }

                leftEven = temp - left;
                ans += leftEven + 1;
            }
        }

        return ans;
    }
};