class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int cnt0 = 0;
        vector<int> cnt;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == x) {
                cnt0++;
                cnt.push_back(i);
            }
        }

        vector<int> ans(queries.size());

        for(int i = 0; i < queries.size(); i++) {
            if(queries[i] <= cnt0)
                ans[i] = cnt[queries[i] - 1];
            else
                ans[i] = -1;
        }

        return ans;
    }
};