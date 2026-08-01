class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long inf = numeric_limits<long long>::min() / 4;
        
        // f[0]=no op, f[1]=in multiply, f[2]=in divide, f[3]=after op
        long long f[4] = {0, inf, inf, inf};
        long long ans = inf;
        
        for (int x : nums) {
            long long nf[4];
            long long mul = 1LL * x * k;
            long long div = x / k;  // C++ truncates toward 0: floor for +, ceil for -
            
            nf[0] = max(f[0], 0LL) + x;           // no operation yet
            nf[1] = max({f[0], f[1], 0LL}) + mul; // currently multiplying
            nf[2] = max({f[0], f[2], 0LL}) + div; // currently dividing
            nf[3] = max({f[1], f[2], f[3]}) + x;  // operation ended, back to normal
            
            for (int i = 0; i < 4; ++i) f[i] = nf[i];
            ans = max({ans, nf[0], nf[1], nf[2], nf[3]});
        }
        return ans;
    }
};