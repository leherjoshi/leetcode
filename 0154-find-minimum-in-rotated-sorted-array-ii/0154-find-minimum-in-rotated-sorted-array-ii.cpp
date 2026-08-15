class Solution {
public:
    int findMin(vector<int>& arr) {
        int low=0;
        int high=arr.size()-1;

        while(low<high){
            int mid=(low+high)/2;

            if(arr[mid]==arr[high]&&arr[low]==arr[mid]){
                low++;
                high--;
                continue;
            }

            if(arr[mid]>arr[high]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return arr[low];
    }
};