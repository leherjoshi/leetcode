class Solution {
public:
    int fun(int n,vector<int>& nums){
      
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int a = nums[0], b = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) {
            int curr = max(nums[i]+a, b);
            a = b;
            b = curr;
        }
        return b;
}
    int rob(vector<int>& nums) {
       int n = nums.size();
        if(n==1) return nums[0];
        vector<int>temp1,temp2;
        for(int i = 0; i < n; i++) {
        if(i!=0)temp1.push_back(nums[i]);
        if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(fun(n-1,temp1),fun(n-1,temp2));
    }
};