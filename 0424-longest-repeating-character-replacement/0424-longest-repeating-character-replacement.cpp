class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int left=0;
        int right=0;
        int cnt=0;
        int maxlen=0;
        unordered_map<char ,int>freq;
        for(int right=0;right<n;right++){
            freq[s[right]]++;
            cnt=max(cnt,freq[s[right]]);
           
            while((right-left+1)-cnt>k){
                freq[s[left]]--;
                left++;
            }

            maxlen =max(maxlen,right-left+1);
        }
        return maxlen;
    }
};