class Solution {
public:
    bool solve(vector<int>stones,int i,int last,vector<vector<int>>&dp){
        if(i==stones.size()-1){
            return true;
        }
         if (dp[i][last] != -1)
            return dp[i][last];

        for(int d=-1;d<2;d++){
            int jump=last+d;
            if (jump <= 0)
                continue;
            int nextpos=stones[i]+jump;
            for(int j=i+1;j<stones.size();j++){
                if(stones[j]==nextpos){
                    if(solve(stones,j,jump,dp)){
                        return dp[i][last]=true;
                    }
                }
                if(stones[j]>nextpos){
                    break;
                }
            }
        }
        return dp[i][last]=false;
    }
   bool canCross(vector<int>& stones) {

        int n = stones.size();

        
        if (stones[1] != 1)
            return false;

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(stones, 0, 0, dp);
    }
};