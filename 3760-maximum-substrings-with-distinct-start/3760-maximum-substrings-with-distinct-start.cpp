class Solution {
public:
    int maxDistinct(string s) {
       unordered_map<char,int>mp;
       int uniq=0;
       for(int i=0;i<s.size();i++){
        // string js=s.substr(i+1,n);
        if(mp.find(s[i])==mp.end()){
            uniq++;
            mp[s[i]]++;
        }
       }
       return uniq;
    }
};