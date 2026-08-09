class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0)
            return false;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[hand[i]]++;
        }

        sort(hand.begin(), hand.end());

        for (int i = 0; i < n; i++) {
            int x = hand[i];

            if (mp[x] == 0)
                continue;

            for (int j = 0; j < groupSize; j++) {
                if (mp[x + j] == 0)
                    return false;

                mp[x + j]--;
            }
        }

        return true;
    }
};