class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

       
        unordered_map<int,int>mp;
        for (int i = 0; i <nums.size(); i++) {
           mp[nums[i]]++;
        }
        vector<int>f;
        for (int i = mn; i <= mx; i++) {
           
           if(mp[i]==0) f.push_back(i);
        }

        return f;
    }
};