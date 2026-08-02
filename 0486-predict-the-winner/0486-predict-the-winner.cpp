class Solution {
public:
    bool solve(int i, int j, int p1, int p2, int chance, vector<int>& nums) {
        if (i > j)
            return p1 >= p2;

        if (chance == 0) {
            return solve(i + 1, j, p1 + nums[i], p2, 1, nums) ||
                   solve(i, j - 1, p1 + nums[j], p2, 1, nums);
        } else {
            return solve(i + 1, j, p1, p2 + nums[i], 0, nums) &&
                   solve(i, j - 1, p1, p2 + nums[j], 0, nums);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        return solve(0, nums.size() - 1, 0, 0, 0, nums);
    }
};