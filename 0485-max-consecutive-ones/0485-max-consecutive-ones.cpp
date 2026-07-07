class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int mx = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                mx=i+1;
            else {
                cnt=max(cnt,i-mx+1);
            }
        }

       
        return cnt;
    }
};