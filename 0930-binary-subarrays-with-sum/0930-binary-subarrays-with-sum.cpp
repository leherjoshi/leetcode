class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        int cnt = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            if (mp.count(sum - goal))
                cnt += mp[sum - goal];

            mp[sum]++;
        }

        return cnt;
    }
};