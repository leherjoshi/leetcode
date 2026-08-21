class Solution {
public:
    int count(int i,string s,vector<int>&dp){
        if(i==s.size())return 1;
        
        if(s[i]=='0')return 0;
        if(dp[i]!=-1)return dp[i];

       int one=count(i+1,s,dp);

       int two=0;

       if(i+1<s.size()&&(s[i]=='1'||(s[i]=='2'&&s[i+1]<='6'))){
        two=count(i+2,s,dp);
       }
       return dp[i]=one+two;


    }
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        return count(0,s,dp);
    }
};