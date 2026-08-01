class Solution {
public:
    long long calc(vector<int>& nums, int k, bool mul) {
        const long long NEG = -(1LL << 60);

        long long no = NEG;     // operation not started
        long long in = NEG;     // inside operated subarray
        long long done = NEG;   // operation finished
        long long ans = NEG;

        for (int x : nums) {
            long long y;

            if (mul)
                y = 1LL * x * k;
            else {
                
                    y = x / k;      // floor
                        // ceil (C++ truncates toward 0)
            }

            long long n_no = max(no + x, 1LL * x);

            long long n_in = max({
                y,
                no + y,
                in + y
            });

            long long n_done = max({
                in + 1LL * x,
                done + 1LL * x
            });

            no = n_no;
            in = n_in;
            done = n_done;

            ans = max({ans, no, in, done});
        }

        return ans;
    }

    long long maxSubarraySum(vector<int>& nums, int k) {
        return max(calc(nums, k, true), calc(nums, k, false));
    }
};