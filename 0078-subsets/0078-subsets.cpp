class Solution {
public:
    vector<vector<int>>solve(int i,vector<int>&nums,vector<int>&ans,vector<vector<int>>&res){
        if(i==nums.size()){
                res.push_back(ans);
                return res;
        }
       
            ans.push_back(nums[i]);
            solve(i+1,nums,ans,res);
             ans.pop_back();
            solve(i+1,nums,ans,res);
        return res;
       
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>arr;
        vector<vector<int>>res;
        return solve(0,nums,arr,res);
    }
};