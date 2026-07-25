class Solution {
public:
    int strStr(string haystack, string needle) {

        if(haystack.find(needle)!=string::npos){
            for(int i=0;i<haystack.size();i++){
                int j=0;
                int k=i;
               while(k<haystack.size()&&j<needle.size()&&haystack[k]==needle[j]){
                    k++;
                    j++;
                   
                }
                if(j==needle.size()){
                    return i;
                }
            }
        }
        return -1;
    }
};