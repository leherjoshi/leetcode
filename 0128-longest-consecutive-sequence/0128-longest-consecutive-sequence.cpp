class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(), nums.end());
        int n = nums.size();
        int mx=0;
        int cnt=1;
            for(int i=0;i<n;i++){
               
                    int curr=nums[i]+1;
                    cnt=1;
                    while(mp.count(curr)){
                        cnt++;
                        curr++;
                    }
                    mx=max(cnt,mx);
                
            }
            return mx;
        
    }
};