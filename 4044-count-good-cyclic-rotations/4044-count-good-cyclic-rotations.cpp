class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;

        long long total = 0;
        for (int x : nums)
            total += x;

        long long sum1 = 0;

        // First rotation
        for (int i = 0; i < mid; i++)
            sum1 += nums[i];

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            long long sum2 = total - sum1;

            if (sum1 > sum2)
                cnt++;

            // Move window one position
            sum1 -= nums[i];
            sum1 += nums[(i + mid) % n];
        }

        return cnt;
    }
};