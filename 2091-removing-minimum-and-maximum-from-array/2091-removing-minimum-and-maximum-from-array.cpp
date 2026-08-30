class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int maxi = 0;
        int mini = 0;

        for(int i = 0; i < n; i++) {
            if(nums[mini] > nums[i]) {
                mini = i;
            }

            if(nums[maxi] < nums[i]) {
                maxi = i;
            }
        }

        int left = max(mini, maxi) + 1;
        int right = n - min(mini, maxi);
        int both = min(mini, maxi) + 1 + n - max(mini, maxi);

        return min(left, min(right, both));
    }
};