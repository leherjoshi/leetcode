class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(int x : nums)
            mp[x]++;
        
        int sum = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1] + 1)
                sum += nums[i];
            else
                break;
        }
        
        while(mp[sum] != 0)
            sum++;
        
        return sum;
    }
};