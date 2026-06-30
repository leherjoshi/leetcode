class Solution {
public:
    int numberOfSubstrings(string s) {
       
       int i=0,j=0,cnt=0;
       int n=s.size();
      vector<int>abc(3,0);
        while(j<s.size()){
             abc[s[j]-'a']++;
             while(abc[0]>0&&abc[1]>0&&abc[2]>0){
                cnt+=n-j;     
                abc[s[i]-'a']--;
                i++;

             }
             j++;
        
        
    }
    return cnt;
    }
};