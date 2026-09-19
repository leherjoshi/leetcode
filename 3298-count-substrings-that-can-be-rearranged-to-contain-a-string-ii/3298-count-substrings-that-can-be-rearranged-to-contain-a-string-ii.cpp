class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> need(26, 0), have(26, 0);

        for(char c : word2)
            need[c - 'a']++;

        int required = word2.size();
        int formed = 0;
        int left = 0;
        long long ans = 0;

        for(int right = 0; right < word1.size(); right++) {
            int x = word1[right] - 'a';
            have[x]++;

            if(have[x] <= need[x])
                formed++;

            while(formed == required) {
                ans += word1.size() - right;

                int y = word1[left] - 'a';

                if(have[y] <= need[y])
                    formed--;

                have[y]--;
                left++;
            }
        }

        return ans;
    }
};