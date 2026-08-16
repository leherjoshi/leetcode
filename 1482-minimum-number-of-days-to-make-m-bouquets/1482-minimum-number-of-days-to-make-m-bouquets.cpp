class Solution {
public:

    bool solve(vector<int>& bl, int m, int k, int mid) {
        int cnt = 0;

        for(int i = 0; i < bl.size(); i++) {
            if(bl[i] <= mid) {
                cnt++;

                if(cnt == k) {
                    m--;
                    cnt = 0;
                }
            }
            else {
                cnt = 0;
            }
        }

        return m <= 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL * m * k > bloomDay.size())
            return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = high;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(solve(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};