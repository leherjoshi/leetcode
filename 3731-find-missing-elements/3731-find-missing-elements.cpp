class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int start=nums[0];
        int end=nums.back();
       // set<int>st(nums.begin(),nums.end());
       int j=0;
        for(int i=start;i<=end-1;i++){
            if(i!=nums[j]){
                ans.push_back(i);
            }else{
                j++;
            }

        }
        return ans;
    }
};