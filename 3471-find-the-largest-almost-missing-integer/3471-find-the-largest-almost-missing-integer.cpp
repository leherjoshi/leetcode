class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int cnt=0;
        if(k==0||k==n)return *max_element(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxi=-1;
        if(k==1){
            for(int i=0;i<n;i++){
                if(mp[nums[i]]==1&&nums[i]>maxi){
                    maxi=nums[i];
                }
            }
            return maxi;
        }

        int first=mp[nums[0]]==1?nums[0]:-1;
        int last=mp[nums[n-1]]==1?nums[n-1]:-1;

        return max(first,last);
        
    }
};