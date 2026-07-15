class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        priority_queue<pair<int,int>> pq;

        int cnt = 1;
        int cur = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == cur)
            {
                cnt++;
            }
            else
            {
                pq.push({cnt, cur});
                cur = nums[i];
                cnt = 1;
            }
        }

        pq.push({cnt, cur});

        vector<int> ans;

        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};