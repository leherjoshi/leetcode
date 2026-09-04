class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

       vector<vector<int>>res;
        sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++){
        if(i>0&&nums[i]==nums[i-1])continue;
        int k=n-1;
            int j=i+1;
            while(j<k){
                int target=nums[i]+nums[j]+nums[k];
                if(target>0){
                        k--;
                        
                }else if(target<0){
                        j++;
                }else{
                    res.push_back({nums[i],nums[j],nums[k]});
                        j++;
                         k--;
                        
                          while(j<k&&nums[j]==nums[j-1])j++;
                           while(j<k&&nums[k]==nums[k+1])k--;

                }
            }
       }
       return res;
    }
};