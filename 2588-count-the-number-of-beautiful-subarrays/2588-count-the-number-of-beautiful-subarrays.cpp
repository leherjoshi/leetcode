class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,long long>freq;
        long long ans=0;
        int px=0;

        freq[0]=1;
        for(int x:nums){
            px^=x;
            ans+=freq[px];
            freq[px]++;
        }
        return ans;
    }
};