class Solution {
public:
    void helper(vector<int>&nums,vector<bool>&used,vector<int>&cur,vector<vector<int>>&res){
        if(cur.size()==nums.size()){
            res.push_back(cur);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(used[i])continue;

            used[i]=true;
            cur.push_back(nums[i]);
            helper(nums,used,cur,res);
            cur.pop_back();
            used[i]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;
        vector<bool>used(nums.size(),false);
        helper(nums,used,curr,res);
        return res;
    }
};