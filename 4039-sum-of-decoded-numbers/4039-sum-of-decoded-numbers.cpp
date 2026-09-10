class Solution {
public:
    long long modpow(long long base, long long exp, long long mod) {
        base %= mod;
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    int sumDecoded(vector<long long>& nums) {
        const long long MOD = 1000000007;
        long long sum = 0;

        for (long long n : nums) {
            long long width = n % 10;
            long long d = n / 10;

            // count total digits in d
            long long temp = d;
            int len = 0;
            while (temp > 0) {
                len++;
                temp /= 10;
            }

            // x = first `width` digits, y = remaining (len - width) digits
            long long divisor = 1;
            for (int i = 0; i < len - width; i++) divisor *= 10;

            long long x = d / divisor;
            long long y = d % divisor;

            sum = (sum + modpow(x, y, MOD)) % MOD;
        }

        return (int)sum;
    }
};