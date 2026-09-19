class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // {value, list index, element index}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        int maxVal = INT_MIN;

        // Put first element of every list into heap
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            maxVal = max(maxVal, nums[i][0]);
        }

        int bestL = 0;
        int bestR = INT_MAX;

        while (true) {
            auto [minVal, listIdx, elementIdx] = pq.top();
            pq.pop();

            // Current range = [minVal, maxVal]
            if (maxVal - minVal < bestR - bestL ||
                (maxVal - minVal == bestR - bestL && minVal < bestL)) {
                bestL = minVal;
                bestR = maxVal;
            }

            // If this list has no more elements, we cannot continue
            if (elementIdx + 1 == nums[listIdx].size()) {
                break;
            }

            // Move to next element in the same list
            int nextVal = nums[listIdx][elementIdx + 1];

            pq.push({nextVal, listIdx, elementIdx + 1});

            maxVal = max(maxVal, nextVal);
        }

        return {bestL, bestR};
    }
};