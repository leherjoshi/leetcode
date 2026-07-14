class Solution {
public:
    bool yes(string s,vector<string>&word){
        for(int i=0;i<word.size();i++){
            if(word[i]==s)return true;
        }
        return false;
    }
    bool solve(int i,string& s,vector<string>&word,vector<int>&dp){
        if(i==s.size())return true;
        if(dp[i]!=-1)return dp[i]==1;
        for(int j=i;j<s.size();j++){
            
            if(yes(s.substr(i,j-i+1),word)){
                if(solve(j+1,s,word,dp)){
                return dp[i]=true;
            }
             }
        }
        return dp[i]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1,-1);
        return solve(0,s,wordDict,dp);
    }
};