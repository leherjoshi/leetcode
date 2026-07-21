class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        k=n-k;

        vector<int>arr=nums;
        for(int i=0;i<n;i++){
            arr[i]=nums[(i+k)%n];
        }   
        nums=arr;
    
         }
};