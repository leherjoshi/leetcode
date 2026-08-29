class Solution {
public:
    string simplifyPath(string path) {
        vector<string>comp;
        vector<string>st;
        stringstream ss(path);
        string cp;
        while(getline(ss,cp,'/')){
            if(cp==""||cp=="."){
                continue;
            }
            if(cp==".."){
                if(!st.empty()){
                    st.pop_back();
                }
            }else{
                st.push_back(cp);
            }
        }
        stringstream simp;
        for(const string & s :st){
            simp<<"/"<<s;
        }
        return simp.str().empty()?"/":simp.str();
    }
};