class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;
        string cur="";

        path+="/";

        for(char c:path){
            if(c=='/'){
                if(cur==".."){
                    if(!st.empty())st.pop_back();
                }else if(cur!=""&&cur!="."){
                    st.push_back(cur);
                }
                cur="";
            }else {
                cur+=c;
            }
        }
        string ans="";
        for(string &s:st){
            ans+="/"+s;
        }
        return ans.empty()?"/":ans;

    }
};