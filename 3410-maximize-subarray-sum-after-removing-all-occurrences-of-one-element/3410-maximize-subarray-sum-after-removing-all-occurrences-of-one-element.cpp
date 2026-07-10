class Solution {
public:
    
    long long maxSubarraySum(vector<int>& nums) {
        
        unordered_map<long long,long long>prev;
       long long res=nums[0];
        long long prefix=0;
       long long low=0;
        prev[0]=0;

        for(auto n:nums){
            prefix+=n;
            res=max(res,prefix-low);

            if(n<0){
                if(prev.count(n)){
                    prev[n]=min(prev[n],prev[0])+n;
                }else{
                    prev[n]=prev[0]+n;
                }
                low=min(low,prev[n]);
            }
            prev[0]=min(prev[0],prefix);
            low=min(low,prev[0]);
        }
        return res;
    }
};