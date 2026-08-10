class Solution {
public:

    vector<bool> is_prime;

    Solution() {
        sieve();
    }

    void sieve() {
        int N = 50000;

        is_prime.assign(N + 1, true);

        is_prime[0] = false;
        is_prime[1] = false;

        for (int i = 2; i <= N; i++) {
            if (is_prime[i]) {
                for (int j = i * 2; j <= N; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }

    long long primeSubarray(vector<int>& nums, int k) {

       

        int n = nums.size();

        deque<int> prime_pos;
        deque<int> max_q;
        deque<int> min_q;

        int l = 0;
        long long ans = 0;

        for (int r = 0; r < n; r++) {

            if (is_prime[nums[r]]) {

                while (!max_q.empty() &&
                       nums[max_q.back()] <= nums[r])
                    max_q.pop_back();

                while (!min_q.empty() &&
                       nums[min_q.back()] >= nums[r])
                    min_q.pop_back();

                max_q.push_back(r);
                min_q.push_back(r);

                prime_pos.push_back(r);
            }

            while (!max_q.empty() &&
                   !min_q.empty() &&
                   nums[max_q.front()] -
                   nums[min_q.front()] > k) {

                l++;

                while (!prime_pos.empty() &&
                       prime_pos.front() < l)
                    prime_pos.pop_front();

                while (!max_q.empty() &&
                       max_q.front() < l)
                    max_q.pop_front();

                while (!min_q.empty() &&
                       min_q.front() < l)
                    min_q.pop_front();
            }

            if (prime_pos.size() >= 2) {
                ans += prime_pos[prime_pos.size() - 2] - l + 1;
            }
        }

        return ans;
    }
};