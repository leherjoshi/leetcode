class Solution {
public:
    bool solve(vector<int>& weights, int days, int mid) {
        int day = 1;
        int sum = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > mid) {
                day++;
                sum = 0;
            }

            sum += weights[i];
        }

        return day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (solve(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};