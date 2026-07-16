class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>gcdd;
        int mxi=0;
    
        for(int i=0;i<nums.size();i++){
            mxi=max(mxi,nums[i]);
            gcdd.push_back(__gcd(nums[i],mxi));
        }
        sort(gcdd.begin(),gcdd.end());
        int low=0;
        int high=gcdd.size()-1;
        long long ans=0;
        while(low<high){
            ans+=__gcd(gcdd[low],gcdd[high]);
            low++;
            high--;
        }
        return ans;
    }
};