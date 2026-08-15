class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);

        if (it == nums.end() || *it != target)
            return {-1, -1};

        auto it2 = upper_bound(nums.begin(), nums.end(), target);

        vector<int> v;
        v.push_back(it - nums.begin());
        v.push_back(it2 - nums.begin() - 1);
        return v;
    }
};