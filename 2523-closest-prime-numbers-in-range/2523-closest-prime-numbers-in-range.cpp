class Solution {
public:
    vector<bool> prime;

    void sieve(int limit) {
        prime.assign(limit + 1, true);

        prime[0] = prime[1] = false;

        for (int i = 2; i * i <= limit; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    prime[j] = false;
                }
            }
        }
    }

    bool isprime(int x) {
        if (x < 2) return false;
        return prime[x];
    }

    vector<int> closestPrimes(int left, int right) {
        sieve(right);

        int prev = -1;
        int a = -1, b = -1;
        int mindiff = INT_MAX;

        for (int i = left; i <= right; i++) {
            if (isprime(i)) {

                if (prev != -1) {
                    if (i - prev < mindiff) {
                        mindiff = i - prev;
                        a = prev;
                        b = i;
                    }
                }

                prev = i;
            }
        }

        return {a, b};
    }
};