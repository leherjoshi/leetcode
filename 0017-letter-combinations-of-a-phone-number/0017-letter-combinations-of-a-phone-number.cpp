class Solution {
public:
    void solve(int i,string digits,string ans,vector<string>&res){
        if(i==digits.size()){
            res.push_back(ans);
            return ;
        }
        if(digits[i]=='2'){
            solve(i+1,digits,ans+'a',res);
            solve(i+1,digits,ans+'b',res);
            solve(i+1,digits,ans+'c',res);
        }else  if(digits[i]=='3'){
            solve(i+1,digits,ans+'d',res);
            solve(i+1,digits,ans+'e',res);
            solve(i+1,digits,ans+'f',res);
        }else  if(digits[i]=='4'){
            solve(i+1,digits,ans+'g',res);
            solve(i+1,digits,ans+'h',res);
            solve(i+1,digits,ans+'i',res);
        }else if(digits[i]=='5'){
            solve(i+1,digits,ans+'j',res);
            solve(i+1,digits,ans+'k',res);
            solve(i+1,digits,ans+'l',res);
        }else  if(digits[i]=='6'){
            solve(i+1,digits,ans+'m',res);
            solve(i+1,digits,ans+'n',res);
            solve(i+1,digits,ans+'o',res);
        }else if(digits[i]=='7'){
            solve(i+1,digits,ans+'p',res);
            solve(i+1,digits,ans+'q',res);
            solve(i+1,digits,ans+'r',res);
            solve(i+1,digits,ans+'s',res);
        }else  if(digits[i]=='8'){
            
            solve(i+1,digits,ans+'t',res);
            solve(i+1,digits,ans+'u',res);
            solve(i+1,digits,ans+'v',res);
        }else if(digits[i]=='9'){
            solve(i+1,digits,ans+'y',res);
            solve(i+1,digits,ans+'w',res);
            
            solve(i+1,digits,ans+'x',res);
            solve(i+1,digits,ans+'z',res);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        solve(0,digits,"",res);
        return res;
    }
};