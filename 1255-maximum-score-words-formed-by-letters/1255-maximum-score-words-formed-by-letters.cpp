class Solution {
public:
    int solve(int i, vector<string>& words, vector<int>& freq, vector<int>& score) {
        if (i == words.size())
            return 0;

        // Option 1: Don't take the current word
        int notTake = solve(i + 1, words, freq, score);

        // Option 2: Try to take the current word
        bool canTake = true;
        int wordScore = 0;

        // Remove letters and calculate score
        for (char c : words[i]) {
            freq[c - 'a']--;
            wordScore += score[c - 'a'];

            if (freq[c - 'a'] < 0)
                canTake = false;
        }

        int take = 0;
        if (canTake) {
            take = wordScore + solve(i + 1, words, freq, score);
        }

        // Restore the letters (Backtracking)
        for (char c : words[i]) {
            freq[c - 'a']++;
        }

        return max(take, notTake);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {

        vector<int> freq(26, 0);

        for (char c : letters)
            freq[c - 'a']++;

        return solve(0, words, freq, score);
    }
};