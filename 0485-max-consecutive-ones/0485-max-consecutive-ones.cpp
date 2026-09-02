class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int mx = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
               mx=0;
            else {
                mx++;
                cnt=max(cnt,mx);
            }
        }

       
        return cnt;
    }
};