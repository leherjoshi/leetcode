class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;

        // 1. Memory: You must size the vectors to avoid crashes
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        // 2. Pre-calculate prefix sums from the left
        left[0] = 0; // Nothing is to the left of the first element
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] + nums[i - 1];
        }

        // 3. Pre-calculate suffix sums from the right
        right[n - 1] = 0; // Nothing is to the right of the last element
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] + nums[i + 1];
        }

        // 4. Find where they match
        for (int i = 0; i < n; i++) {
            if (left[i] == right[i]) return i;
        }

        return -1;
    }
};