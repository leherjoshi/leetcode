class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=0;
        int j=n;
        vector<int> s  ;
        while(i<n &&j<nums.size()){
            s.push_back(nums[i]);
            s.push_back(nums[j]);
            i++;
            j++;
        }
        return s;
    }
};