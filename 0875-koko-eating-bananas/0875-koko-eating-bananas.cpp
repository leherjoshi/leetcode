class Solution {
public:
    bool solve(vector<int>& piles, int h, int mid) {
        long long cnt = 0;

        for(int i = 0; i < piles.size(); i++) {
            cnt += (piles[i] + mid - 1) / mid;
        }

        return cnt <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(solve(piles, h, mid)) {
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