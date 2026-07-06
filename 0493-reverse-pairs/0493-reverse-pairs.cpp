class Solution {
public:
    int cnt;

    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp;

        int i = left;
        int j = mid + 1;

        // Merge the two sorted halves
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
             
                temp.push_back(arr[j++]);
            }
        }

        // Copy remaining elements of left half
        while (i <= mid) {
            temp.push_back(arr[i++]);
        }

        // Copy remaining elements of right half
        while (j <= right) {
            temp.push_back(arr[j++]);
        }

        // Copy back to original array
        for (int k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }
    }

    void mergesort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        mergesort(nums, l, mid);
        mergesort(nums, mid + 1, r);
        int j = mid + 1;

        for (int i = l; i <= mid; i++) {
            while (j <= r && (long long)nums[i] > 2LL * nums[j])
                j++;
            cnt += j - (mid + 1);
        }
        merge(nums, l, mid, r);
    }
    int reversePairs(vector<int>& nums) {
        cnt = 0;
        mergesort(nums, 0, nums.size() - 1);
        return cnt;
    }
};