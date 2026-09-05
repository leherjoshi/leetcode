class Solution {
public:
    int atMost(vector<int>&nums,int k){
        int left=0;
        int count=0;
        int sum=0;

        for(int right=0;right<nums.size();right++){
            if(nums[right]%2!=0)count++;
            while(count>k){
                if(nums[left]%2!=0)count--;
                left++;
            }
            sum+=right-left+1;

        }
        return sum;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};