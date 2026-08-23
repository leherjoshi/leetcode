class Solution {
public:
    void solve(vector<int>& nums, int idx, vector<int>& ans,
               vector<vector<int>>& res, vector<int>& visited) {

        if(ans.size() == nums.size()) {
            res.push_back(ans);
            return;
        }

        if(idx == nums.size()) {
            return;
        }

        // Take nums[idx]
        if(!visited[idx]) {
            visited[idx] = 1;
            ans.push_back(nums[idx]);

            solve(nums, 0, ans, res, visited);

            ans.pop_back();
            visited[idx] = 0;
        }

        // Not Take nums[idx]
        solve(nums, idx + 1, ans, res, visited);
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        vector<int> visited(nums.size(), 0);

        solve(nums, 0, ans, res, visited);

        return res;
    }
};