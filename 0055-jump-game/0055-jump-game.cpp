class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        int end = 0;

        if(nums.size() == 1)
            return true;

        for(int i = 0; i < nums.size(); i++) {

            if(i > farthest)
                return false;

            farthest = max(farthest, nums[i] + i);

            if(farthest > end) {
                end = farthest;

                if(end >= nums.size() - 1)
                    return true;
            }
        }

        return false;
    }
};