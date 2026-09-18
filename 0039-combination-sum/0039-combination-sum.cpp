class Solution {
public:
    void solve(int i,int target,vector<int>&cand,vector<int>&ans,vector<vector<int>>&res){
        if(i==cand.size()){
            if(target==0){
                res.push_back(ans);
            }
            return ;
        }
        if(target-cand[i]>=0){
        ans.push_back(cand[i]);
        solve(i,target-cand[i],cand,ans,res);
        ans.pop_back();
        }
        solve(i+1,target,cand,ans,res);

        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
         vector<int> comb;
        solve(0,target,candidates, comb, res );
        return res;

    }
};