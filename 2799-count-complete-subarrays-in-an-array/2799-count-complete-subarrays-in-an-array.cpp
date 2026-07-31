class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        int res=0;
        int k = unordered_set<int>(nums.begin(),nums.end()).size();
        unordered_map<int, int> mpp;

        for(int right=0;right<n;right++){
            mpp[nums[right]]++;
            while(mpp.size()==k){
                res+=nums.size()-right;
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0)mpp.erase(nums[left]);
                left++;
            }
        }
        return res;
    }
};