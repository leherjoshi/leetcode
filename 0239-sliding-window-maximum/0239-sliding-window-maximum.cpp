class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        int maxi = *max_element(nums.begin(), nums.begin() + k);

        for (int i = 0; i < k; i++)
            pq.push({nums[i], i});
        ans.push_back(maxi);
        for (int i = k; i < nums.size(); i++) {
            pq.push({nums[i], i});
            auto cell = pq.top();
            maxi = cell.first;
            int j = cell.second;
            // if (j >= i-k+1)
            //     ans.push_back(maxi);

          while (!pq.empty() && pq.top().second <= i-k)
                    pq.pop();

         ans.push_back(pq.top().first);
        }
        return ans;
    }
};