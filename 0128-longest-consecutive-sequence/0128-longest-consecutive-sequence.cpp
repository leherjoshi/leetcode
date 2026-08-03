class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (int x : nums) {

            if (mp.count(x))
                continue;

            int left = mp.count(x - 1) ? mp[x - 1] : 0;
            int right = mp.count(x + 1) ? mp[x + 1] : 0;

            int len = left + right + 1;

            mp[x] = len;
            mp[x - left] = len;
            mp[x + right] = len;

            ans = max(ans, len);
        }

        return ans;
    }
};