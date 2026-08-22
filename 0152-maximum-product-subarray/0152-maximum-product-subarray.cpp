class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=1;
        int mini=1;

        int ans=INT_MIN;

        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(nums[i]<0){
                swap(mini,maxi);

            }

            maxi=max(x,x*maxi);
            mini=min(x,x*mini);

            ans=max(ans,maxi);
        }
        return ans;

        
    }
};