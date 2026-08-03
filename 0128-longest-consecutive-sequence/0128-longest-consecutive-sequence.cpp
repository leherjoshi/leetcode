class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int maxlen = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] == nums[i])
                continue;
            else if (nums[i + 1] == nums[i] + 1)
                cnt++;
            else
                cnt = 1;

            maxlen = max(maxlen, cnt);
        }

        return maxlen;
    }
};