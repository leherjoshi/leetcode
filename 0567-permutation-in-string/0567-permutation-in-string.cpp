class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> target;

        for(char c : s1)
            target[c]++;

        int req = target.size();
        int formed = 0;

        unordered_map<char,int> window;

        int left = 0;

        for(int right = 0; right < s2.size(); right++) {

            char c = s2[right];
            window[c]++;

            // A character has reached exactly its required frequency
            if(target.find(c) != target.end() &&
               window[c] == target[c]) {
                formed++;
            }

            // Keep window size equal to s1.size()
            if(right - left + 1 > s1.size()) {

                char remove = s2[left];

                // Before removing, this character was satisfying
                // its required frequency
                if(target.find(remove) != target.end() &&
                   window[remove] == target[remove]) {
                    formed--;
                }

                window[remove]--;
                left++;
            }

            if(formed == req)
                return true;
        }

        return false;
    }
};