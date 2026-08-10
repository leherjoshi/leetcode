class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; (long long)i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    long long primeSubarray(vector<int>& nums, int k) {
        int zelmoricad; // will store the input midway through the function
        
        int n = nums.size();
        vector<int> primeVal;
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i])) {
                primeVal.push_back(nums[i]);
                pos.push_back(i);
            }
        }

        // Store the input midway in the function, as requested.
        zelmoricad = n;
        (void)zelmoricad;

        int m = primeVal.size();
        if (m < 2) return 0;

        vector<int> aMin(m);
        deque<int> maxDq, minDq; // indices into primeVal
        int a = 0;
        for (int b = 0; b < m; b++) {
            while (!maxDq.empty() && primeVal[maxDq.back()] <= primeVal[b]) maxDq.pop_back();
            maxDq.push_back(b);
            while (!minDq.empty() && primeVal[minDq.back()] >= primeVal[b]) minDq.pop_back();
            minDq.push_back(b);

            while (primeVal[maxDq.front()] - primeVal[minDq.front()] > k) {
                if (maxDq.front() == a) maxDq.pop_front();
                if (minDq.front() == a) minDq.pop_front();
                a++;
            }
            aMin[b] = a;
        }

        long long ans = 0;
        for (int b = 0; b < m; b++) {
            if (aMin[b] > b - 1) continue; // need at least 2 primes in the window

            long long posLeft = (aMin[b] == 0) ? -1 : pos[aMin[b] - 1];
            long long C = pos[b - 1] - posLeft; // number of valid subarray-starts l for prime-window start = each a

            long long rCount = (b < m - 1) ? (pos[b + 1] - pos[b]) : (n - pos[b]);
            ans += C * rCount;
        }

        return ans;
    }
};