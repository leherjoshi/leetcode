class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;

        vector<bool> isprime(n, true);
        isprime[0] = isprime[1] = false;

        for(int i = 2; i <= sqrt(n); i++) {
            if(isprime[i]) {
                for(int j = i * i; j < n; j += i) {
                    isprime[j] = false;
                }
            }
        }

        int cnt = 0;

        for(int i = 2; i < n; i++) {
            if(isprime[i])
                cnt++;
        }

        return cnt;
    }
};