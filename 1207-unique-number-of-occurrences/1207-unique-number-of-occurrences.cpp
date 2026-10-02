class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        unordered_set<int> st;

        for (auto m : mp) {
            if (st.count(m.second))
                return false;

            st.insert(m.second);
        }

        return true;
    }
};