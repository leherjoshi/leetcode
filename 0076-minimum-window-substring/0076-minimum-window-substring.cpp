class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int left = 0;
        
        int ansleft = 0;
        int ansright = 0;
        int ans = INT_MAX;

        unordered_map<char, int> dict;
        
        for (char c : t)
            dict[c]++;

        int required = dict.size();

        unordered_map<int, int> windowcount;

        int formed = 0;

        for(int right=0;right<n;right++){

            char c = s[right];

            windowcount[c]++;

            if (dict.find(c) != dict.end() && windowcount[c] == dict[c]) {
                formed++;
            }

            while ( formed == required) {
                c = s[left];

                if (right - left + 1 < ans) {
                    ans = right - left + 1;
                    ansleft = left;
                }
                windowcount[c]--;
                left++;
                if (dict.find(c) != dict.end() && windowcount[c] < dict[c]) {
                    formed--;
                }
            }
            
        }
        return (ans == INT_MAX) ? "" : s.substr(ansleft, ans);
    }
};