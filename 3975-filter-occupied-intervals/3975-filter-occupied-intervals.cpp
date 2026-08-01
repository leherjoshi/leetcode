class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occ,
                                                int freeStart, int freeEnd) {

        sort(occ.begin(), occ.end());

        vector<vector<int>> merged;

        int l = occ[0][0], r = occ[0][1];

        for (int i = 1; i < occ.size(); i++) {
            if (occ[i][0] <= r + 1) {      // overlap or touch
                r = max(r, occ[i][1]);
            } else {
                merged.push_back({l, r});
                l = occ[i][0];
                r = occ[i][1];
            }
        }
        merged.push_back({l, r});

        vector<vector<int>> ans;

        for (auto &v : merged) {
            l = v[0];
            r = v[1];

            // No overlap with free interval
            if (r < freeStart || l > freeEnd) {
                ans.push_back({l, r});
            }
            // Free interval is inside occupied interval
            else if (l < freeStart && r > freeEnd) {
                if (l <= freeStart - 1)
                    ans.push_back({l, freeStart - 1});
                if (freeEnd + 1 <= r)
                    ans.push_back({freeEnd + 1, r});
            }
            // Left part remains
            else if (l < freeStart) {
                ans.push_back({l, freeStart - 1});
            }
            // Right part remains
            else if (r > freeEnd) {
                ans.push_back({freeEnd + 1, r});
            }
            // Else: interval completely removed
        }

        return ans;
    }
};