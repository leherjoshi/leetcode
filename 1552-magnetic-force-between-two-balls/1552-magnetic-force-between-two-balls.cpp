class Solution {
public:
    bool okay(vector<int>arr,int k,int maxi){
        int last=arr[0];
        int cnt=1;
        for(int i=1;i<arr.size();i++){
             if(arr[i]-last>=maxi){
                 cnt++;
                 last=arr[i];
                 
             }
        }
        if(k>cnt)return false;
        else return true;
    }
    int maxDistance(vector<int>& arr, int k) {
         sort(arr.begin(),arr.end());
        int high=*max_element(arr.begin(),arr.end());
        int low=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(okay(arr,k,mid)){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;
    }
};