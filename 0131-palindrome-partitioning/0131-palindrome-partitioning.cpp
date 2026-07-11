class Solution {
public:
int n;
   bool ispalindrone(string s){
    int i = 0;
    int j = s.size();

    while(i < j/2){
        if(s[i] != s[j-i-1])
            return false;
        i++;
    }
    return true;
}
    void solve(string s,int idx,vector<vector<string>>&res,vector<string>&ans){
            if(idx==n){
                res.push_back(ans);
                return;
            }
            for(int i=idx;i<n;i++){
                if(ispalindrone(s.substr(idx,i-idx+1))){
                    ans.push_back(s.substr(idx,i-idx+1));
                    solve(s,i+1,res,ans);
                    ans.pop_back();
                }
            }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>ans;
        n =s.size();
       solve(s,0,res,ans);
       return res;
        
    }
};