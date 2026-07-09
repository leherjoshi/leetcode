class Solution {
public:
void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& comb, int i, int tar) {
        if (tar == 0) {
            ans.push_back(comb);
            return;
        }
        if (i == nums.size() || tar < 0) {
            return;
        }
       
        comb.push_back(nums[i]);

        solve(nums, ans, comb, i+1, tar - nums[i]); 

        comb.pop_back() ;
         while(i+1<nums.size()&&nums[i]==nums[i+1])i++;
        solve(nums, ans, comb, i + 1, tar);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
         vector<int> comb;
        solve(candidates, res, comb, 0, target);
        return res;
    }
};