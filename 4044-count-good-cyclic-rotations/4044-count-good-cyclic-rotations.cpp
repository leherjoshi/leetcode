class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int mid = n / 2;
        long long sum1 = 0;
        long long sum2 = 0;

        for (int i = 0; i < n; i++) {
            if (i < mid) {
                sum1 += nums[i];
            } else {
                sum2 += nums[i];
            }
        }

        for (int i = 0; i < n; i++) {

            if (sum1 > sum2) {
                cnt++;
            }

            sum1 = sum1 - nums[i] + nums[(mid + i) % n];
            sum2 = sum2 + nums[i] - nums[(mid + i) % n];
        }

        return cnt;
    }
};