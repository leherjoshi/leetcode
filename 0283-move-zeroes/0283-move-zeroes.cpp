class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        while(i<n){
            while(j<n&&nums[j]==0){
                j++;
            }
            if(j==n)break;
            swap(nums[i],nums[j]);

            i++;
            j++;

        }
    }
};