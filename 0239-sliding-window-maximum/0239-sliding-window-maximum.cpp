class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // step 1: pop smaller elements from the back
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }

            // step 2: push i to the back
            dq.push_back(i);

            // step 3: pop expired index from the front
            if (dq.front() <= i - k) {
                dq.pop_front();
            }

            // step 4: once a full window exists, record the max
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};