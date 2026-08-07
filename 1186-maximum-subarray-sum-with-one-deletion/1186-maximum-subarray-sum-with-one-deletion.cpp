class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int keep = arr[0], drop = 0; // drop=0 means "no element deleted yet at i=0"
        int ans = arr[0];
        for (int i = 1; i < n; i++) {
            drop = max(drop + arr[i], keep);      // delete arr[i], or had already deleted earlier
            keep = max(keep, 0) + arr[i];          // no deletion so far: extend or restart
            ans = max({ans, keep, drop});
        }
        return ans;
    }
};