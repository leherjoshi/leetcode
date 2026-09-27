class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& used,
               vector<int>& ans, vector<vector<int>>& res) {

        if(i == nums.size()){
            res.push_back(ans);
            return;
        }

        for(int ind = 0; ind < nums.size(); ind++){
            if(!used[ind]){
                used[ind] = 1;
                ans.push_back(nums[ind]);

                solve(i+1, nums, used, ans, res);

                used[ind] = 0;
                ans.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        vector<int> used(nums.size(), 0);

        solve(0, nums, used, ans, res);

        return res;
    }
};