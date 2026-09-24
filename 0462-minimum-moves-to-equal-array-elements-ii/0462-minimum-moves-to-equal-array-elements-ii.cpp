class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int mid = nums[nums.size()/2];
        int mx = 0;

        for(int i = 0; i < nums.size(); i++) {
            mx += abs(mid - nums[i]);
        }

        return mx;
    }
};