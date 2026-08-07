#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumSum(std::vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        // maxNoDelete: Standard Kadane's state (no elements deleted).
        int maxNoDelete = arr[0];
        
        // maxOneDelete: Max sum ending at i with one element deleted.
        int maxOneDelete = arr[0];
        int result = arr[0];

        for (int i = 1; i < n; i++) {
            int prevNoDelete = maxNoDelete;

            // Update no-deletion state (Standard Kadane).
            maxNoDelete = std::max(maxNoDelete + arr[i], arr[i]);

            /* Update one-deletion state:
               - Keep current element but a past element was deleted.
               - Delete current element (take previous no-delete sum).
            */
            maxOneDelete = std::max(maxOneDelete + arr[i], prevNoDelete);

            result = std::max({result, maxNoDelete, maxOneDelete});
        }
        return result;
    }
};