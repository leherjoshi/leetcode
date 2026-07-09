class Solution {
public:
  
    void helper(vector<int>& nums,
                vector<bool>& used,
                vector<int>& current,
                vector<vector<int>>& result) {

        // Base case
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
             
            if(i>0&&nums[i]==nums[i-1]&&!used[i-1])continue;
            // include
            used[i] = true;
            current.push_back(nums[i]);

            helper(nums, used, current, result);
           
            // backtrack
            
            current.pop_back();
            
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        helper(nums, used, current, result);
        return result;
    }
};