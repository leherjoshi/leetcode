class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        int i=0;
        int j=0;
        while(i<nums.size()&&j<nums.size()){
            while(i<nums.size()&&nums[i]<0){
                i++;

            }
            ans.push_back(nums[i++]);
             while(j<nums.size()&&nums[j]>0){
                j++;

            } 
            ans.push_back(nums[j++]);

        }
        return ans;
    }
};