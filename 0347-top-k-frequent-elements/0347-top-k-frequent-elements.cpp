class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        sort(nums.begin(), nums.end());

        int pre = nums[0];
        int prenum = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == pre) {
                prenum++;
            }
            else {
                pq.push({prenum, pre});
                pre = nums[i];
                prenum = 1;
            }
        }

        // store last number
        pq.push({prenum, pre});

        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};