class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>freq(26,0);
        for(char a:magazine)freq[a-'a']++;
        for(char a:ransomNote)freq[a-'a']--;
        for(int i=0;i<26;i++){
            if(freq[i]<0)return false;
        }
        return true;
    }
};