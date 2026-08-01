class Solution {
public:
    long long func(vector<int>& nums, vector<long long>&temp){
        int n=nums.size();
        long long mn = -4e18;
        long long s0=mn, s1=mn, s2=mn, res=mn;

        for(int i=0; i<n; i++){
            long long x1=nums[i];
            long long x2=temp[i];
            long long n0 = max(s0+x1, x1);
            long long n1 = max({x2,s0+x2,s1+x2});
            long long n2 = max({s1 + x1, s2 + x1});

            s0 =n0;
            s1=n1;
            s2=n2;
            res=max({res,s1,s2});
        }
        return res;
    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>multii(n); vector<long long>div(n);
        for(int i=0; i<n; i++){
            multii[i]=1LL * nums[i] * k;
            if(nums[i]>=0)div[i]=nums[i]/k;
            else  div[i] = -((-nums[i]) / k);
        }
        return max(func(nums, multii), func(nums, div));
    }
};