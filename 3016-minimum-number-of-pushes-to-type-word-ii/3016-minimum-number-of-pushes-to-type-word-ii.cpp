class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int>freq(26,0);
        int ans = 0;
        for(char c:word)freq[c-'a']++;
        sort(freq.rbegin(),freq.rend());
        for (int i = 0; i < 26 ; i++) {

            ans += freq[i]*(i / 8 + 1);
        }

        return ans;
    }
};