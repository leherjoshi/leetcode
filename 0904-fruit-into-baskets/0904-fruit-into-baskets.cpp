class Solution {
public:
    int totalFruit(vector<int>& s) {
        unordered_map<int, int> mp;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            mp[s[right]]++;

            while (mp.size() > 2) {
                mp[s[left]]--;

                if (mp[s[left]] == 0)
                    mp.erase(s[left]);

                left++;
            }

          
                ans = max(ans, right - left + 1);
            
        }
        return ans;
    }
};