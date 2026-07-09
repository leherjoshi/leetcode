class Solution {
public:
vector<vector<int>>solve(int idx,vector<int>& cand,int target,vector<vector<int>>&res,vector<int>&ans)
    {   
        if(target==0){
            res.push_back(ans);
            return res;
        }
        if(idx==cand.size()){
            return res;
        }
        for(int i=idx;i<cand.size();i++){
             if (cand[i] > target)
                continue;
            ans.push_back(cand[i]);
            solve(i,cand,target-cand[i],res,ans);
            ans.pop_back();
           
        }
        return res;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ans;
        return solve(0,candidates,target,res,ans);
    }
};