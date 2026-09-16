class Solution {
public:
    bool palindrone(string s){
        int n=s.size();
       for(int i=0;i<s.size();i++){
        if(s[i]!=s[n-i-1])return false;
       }
       return true;
    }
    int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i==0||j==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        if(s1[i-1]==s2[j-1])return dp[i][j]=1+solve(s1,s2,i-1,j-1,dp);

        return dp[i][j]=max(solve(s1,s2,i-1,j,dp),solve(s1,s2,i,j-1,dp));
    }
    int minInsertions(string s1) {
        int n=s1.size();
        string s2=s1;
        reverse(s2.begin(),s2.end());
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        // for(int i =1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
        //          else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //     }
        // }

        solve(s1,s2,n,n,dp);
                return n-dp[n][n];
    }
};