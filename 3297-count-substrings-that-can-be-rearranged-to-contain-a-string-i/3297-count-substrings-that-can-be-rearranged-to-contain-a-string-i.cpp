class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        unordered_map<char, int> need, window;

        for(char c : word2)
            need[c]++;

        int left = 0;
        long long ans = 0;

        for(int right = 0; right < word1.size(); right++) {
            window[word1[right]]++;

            while(true) {
                bool valid = true;

                for(auto [c, freq] : need) {
                    if(window[c] < freq) {
                        valid = false;
                        break;
                    }
                }

                if(!valid) break;

                ans += word1.size() - right;

                window[word1[left]]--;
                left++;
            }
        }

        return ans;
    }
};