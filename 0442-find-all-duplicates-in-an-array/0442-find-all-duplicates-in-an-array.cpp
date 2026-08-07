class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        // Mark visited numbers
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;

            if (nums[idx] < 0){
                ans.push_back(idx+1);
            }
            
            if (nums[idx] > 0)
                nums[idx] = -nums[idx];
        }

        // Collect missing numbers
        
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] > 0)
        //         ans.push_back(i + 1);
        // }

        return ans;
    }
};