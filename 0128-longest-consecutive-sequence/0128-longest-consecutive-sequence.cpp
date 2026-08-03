class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int x : st) {

            // Start only from the beginning of a sequence
            if (!st.count(x - 1)) {

                int cnt = 1;
                int curr = x;

                while (st.count(curr + 1)) {
                    cnt++;
                    curr++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};