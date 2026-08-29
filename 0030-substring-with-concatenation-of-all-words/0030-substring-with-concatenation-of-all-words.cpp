class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int numWords = words.size();
        int windowLen = wordLen * numWords;
        int n = s.size();
        if (n < windowLen) return result;

        unordered_map<string, int> target;
        for (auto& w : words) target[w]++;

        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int count = 0; // number of words currently matched in window
            unordered_map<string, int> window;

            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string w = s.substr(right, wordLen);

                if (target.find(w) == target.end()) {
                    // word not in target: reset window
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                window[w]++;
                count++;

                // if this word now exceeds needed count, shrink from left
                while (window[w] > target[w]) {
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    count--;
                    left += wordLen;
                }

                if (count == numWords) {
                    result.push_back(left);
                    // slide left forward by one word to look for next match
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    count--;
                    left += wordLen;
                }
            }
        }

        return result;
    }
};