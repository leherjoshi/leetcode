class Solution {
public:
    void solve(int i, string mid, vector<string>& ans, string s, int parts) {

        if(parts == 4) {
            if(i == s.size()) {
                mid.pop_back();
                ans.push_back(mid);
            }
            return;
        }

       string st="";
       
       for(int j =i;j<i+3&&j<s.size();j++){
        st+=s[j];
        if(st.size()>1&&st[0]=='0')break;
        if(stoi(st)>255)break;
        solve(j+1,mid+st+'.',ans,s,parts+1);
       }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;

        solve(0, "", ans, s, 0);

        return ans;
    }
};