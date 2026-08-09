class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(), s.end());

        vector<int> mp(26, 0);

        for (int i = 0; i < s.size(); i++) {
            mp[s[i] - 'a']++;
        }

        unordered_map<int, int> mp2;

        for (int i = 0; i < 26; i++) {
            if (mp[i] > 0)
                mp2[mp[i]]++;
        }

        int cnt = 0;

        for (int i = 0; i < 26; i++) {

            while (mp[i] > 0 && mp2[mp[i]] > 1) {
                mp2[mp[i]]--;

                mp[i]--;
                cnt++;

                if (mp[i] > 0)
                    mp2[mp[i]]++;
            }
        }

        return cnt;
    }
};