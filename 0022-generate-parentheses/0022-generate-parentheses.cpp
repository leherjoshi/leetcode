class Solution {
public:
    void solve(int i,int j,int n,vector<string>&ans,string s){
        if(i==n && j==n ){
            ans.push_back(s);
            return ;
        }

        if(i<n){
            solve(i+1,j,n,ans,s+'(');
        }

        if(j<i){
            solve(i,j+1,n,ans,s+')');
        }
        
        return ;
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
         solve(0,0,n,ans,"");
        return ans;
    }
};