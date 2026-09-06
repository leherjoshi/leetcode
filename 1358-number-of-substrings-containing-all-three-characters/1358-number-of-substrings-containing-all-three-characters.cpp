class Solution {
public:
    int atMost(string s,int k){
        unordered_map<char,int>mp;

        int left=0;
        int count=0;
        int len=0;
        for(int right=0;right<s.size();right++){
            mp[s[right]]++;
            while(mp.size()>k){
                mp[left]--;
                if(mp[s[left]]==0)mp.erase(s[left]);
                left++;

            }
            len+=right-left+1;
        }
        return len;
    }
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;

        int left=0;
        int count=0;
    
        for(int right=0;right<s.size();right++){
            mp[s[right]]++;

            while(mp.size()==3){
                count+=s.size()-right;
                mp[s[left]]--;
                if(mp[s[left]]==0)mp.erase(s[left]);
                left++;

            }

        }
        return count;
    }
};