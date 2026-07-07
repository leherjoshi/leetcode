class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

       set<vector<int>>res;
        sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++){
        int k=n-1;
            int j=i+1;
            while(j<k){
                int target=nums[i]+nums[j]+nums[k];
                if(target>0){
                        k--;
                        
                }else if(target<0){
                        j++;
                }else{
                    res.insert({nums[i],nums[j],nums[k]});
                        j++;
                         k--;
                }
            }
       }
       return vector<vector<int>>(res.begin(),res.end());
    }
};