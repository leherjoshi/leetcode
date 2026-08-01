class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for (int right = 0; right < cards.size(); right++) {
            if (mp.find(cards[right]) != mp.end()) {
                ans = min(ans, right - mp[cards[right]] + 1);
            }
            mp[cards[right]] = right;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};