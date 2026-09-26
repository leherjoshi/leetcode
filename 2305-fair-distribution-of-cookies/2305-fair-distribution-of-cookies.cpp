class Solution {
public:
    bool check(vector<int>& cookies, int k, int mid, int idx, vector<int>& child) {
        if (idx == cookies.size())
            return true;

        for (int i = 0; i < k; i++) {
            if (child[i] + cookies[idx] <= mid) {
                child[i] += cookies[idx];

                if (check(cookies, k, mid, idx + 1, child))
                    return true;

                child[i] -= cookies[idx];
            }

            // If this child is empty, trying other empty children
            // gives the same state.
            if (child[i] == 0)
                break;
        }

        return false;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int low = *max_element(cookies.begin(), cookies.end());
        int high = accumulate(cookies.begin(), cookies.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;

            vector<int> child(k, 0);

            if (check(cookies, k, mid, 0, child))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};