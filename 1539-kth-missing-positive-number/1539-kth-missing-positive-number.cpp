class Solution {
public:
    unordered_map<int,int> mp;

    bool iskth(vector<int>& arr, int k, int x) {
        int missing = 0;

        for (int i = 1; i <= x; i++) {
            if (mp.find(i) == mp.end())
                missing++;

            if (missing >= k)
                return true;
        }

        return false;
    }

    int findKthPositive(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++)
            mp[arr[i]]++;

        int low = 1;
        int high = arr.back() + k;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (iskth(arr, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};