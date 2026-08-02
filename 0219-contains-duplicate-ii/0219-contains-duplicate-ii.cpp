class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int left = 0;

        for(int right = 0; right < nums.size(); right++) {

            if(mp.count(nums[right]))
                return true;

            mp[nums[right]]++;

            if(right - left == k) {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0)
                    mp.erase(nums[left]);
                left++;
            }
        }

        return false;
    }
};