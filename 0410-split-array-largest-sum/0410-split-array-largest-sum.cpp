class Solution {
  public:
  
    bool solve(vector<int>&arr,int k,int maxi){
        int cnt=1;
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>maxi)return false;
            
            if(sum+arr[i]>maxi){
                cnt++;
                sum=0;
            }
                sum+=arr[i];
            
            
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& arr, int k) {
        
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(solve(arr,k,mid)){
                ans=mid;
                high=mid-1;
                
                
            }else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};