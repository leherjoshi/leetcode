class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<vector<int>>ans(2);
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]++;

        }
         unordered_map<int,int>mp2;

        for(int i=0;i<nums2.size();i++){           
            mp2[nums2[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
             if(mp[nums2[i]]==0){
                ans[1].push_back(nums2[i]);
                mp[nums2[i]]++;
             }
        }

        for(int i=0;i<nums1.size();i++){
            if(mp2[nums1[i]]==0){
                 mp2[nums1[i]]++;
                 ans[0].push_back(nums1[i]);}
        
        }
        
        return ans;


    }
};