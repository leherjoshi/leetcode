class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int k=-1;
     //  sort(strs.begin(),strs.end(),greater<string>[]);
        for(int i =0;i<strs[0].size();i++){
            bool mtch=true;
            char c=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(c!=strs[j][i]){
                    mtch=false;
                    break;
                }

            }
            if (mtch==false)break;
            else k++;

        }
        return (k==-1)?"":strs[0].substr(0,k+1);
    } 
};