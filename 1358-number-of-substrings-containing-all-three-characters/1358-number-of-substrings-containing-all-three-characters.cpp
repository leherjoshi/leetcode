class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>abc(3,0);

        int l=0;
        
        int cnt=0;
        for(int r=0;r<s.size();r++){
            abc[s[r]-'a']++;
            while(abc[0]>0&&abc[1]>0&&abc[2]>0){
                cnt+=s.size()-r;
                abc[s[l]-'a']--;
                l++;
            }

        }
        return cnt;
    }
};