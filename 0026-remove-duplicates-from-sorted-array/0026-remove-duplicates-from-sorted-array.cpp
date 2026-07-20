class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        
        int n = nums.size();
        vector<int>ans;
        while(i<n){
            ans.push_back(nums[i]);
            while(i+1<n&&nums[i]==nums[i+1]){
                i++;
            }
            i++;
        }
        int a=ans.size();
        for(int in=0;in<a;in++){
            nums[in]=ans[in];
        }
        return a;
    }
};