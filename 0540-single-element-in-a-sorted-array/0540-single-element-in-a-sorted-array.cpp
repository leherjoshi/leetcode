class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {

        int low = 0;
        int high = arr.size() - 1;
        int ans=arr[0];
        while (low < high) {

            int mid = (low + high) / 2;

            if (mid % 2 == 1)
                mid--;

            if (arr[mid] == arr[mid + 1]){
                low = mid + 2;
                ans=arr[low];
            }
                
            else{
                high = mid;
                }
        }

        return ans;
    }
};