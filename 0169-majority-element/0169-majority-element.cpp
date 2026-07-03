class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int maxi;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                maxi=nums[i];
            }
            if(nums[i]==maxi){
                cnt++;
            }else{
                cnt--;
            }
        }
        return maxi;
    }
};