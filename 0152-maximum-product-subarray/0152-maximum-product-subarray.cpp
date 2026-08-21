class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            if(x < 0)
                swap(maxi, mini);

            maxi = max(x, maxi * x);
            mini = min(x, mini * x);

            ans = max(ans, maxi);
        }

        return ans;
    }
};