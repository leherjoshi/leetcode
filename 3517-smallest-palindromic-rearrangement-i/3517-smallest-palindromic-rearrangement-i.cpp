class Solution {
public:
    string smallestPalindrome(string s) {
       
        int n=s.size();
         if(n==1)return s;
        vector<int>freq(26,0);
        for(char c:s)
        freq[c-'a']++;
        int one=-1;
       
        string ans="";
        for(int i=0;i<26;i++){
            if(freq[i]==0){
                continue;
            }
            if(freq[i]%2==1){
                one=i;
            }
            ans+=string(freq[i]/2,i+'a');
        }
        
        string re=ans;
        reverse(ans.begin(),ans.end());
        if(one!=-1)re+=one+'a';
        re+=ans;
        return re;
    }
};