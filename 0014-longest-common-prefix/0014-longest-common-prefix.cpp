class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        bool t=true;
         int maxi = strs[0].size();
        for(int i=0;i<strs[0].size();i++){
            char c=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if (strs[j][i]!=c){
                    maxi=i;
                    t=false;
                    break;

                }

            }
            if(t==false)break;
        }
        return strs[0].substr(0,maxi);
    }
};