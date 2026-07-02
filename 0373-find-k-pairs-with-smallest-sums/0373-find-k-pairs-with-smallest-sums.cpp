class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                       vector<int>& nums2,
                                       int k) {

        vector<vector<int>> ans;

        if (nums1.empty() || nums2.empty() || k == 0)
            return ans;

        // (sum, i, j)
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        // Push the first element of each row (up to k rows)
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while (!pq.empty() && k--) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});

            // Push the next element in the same row
            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return ans;
    }
};