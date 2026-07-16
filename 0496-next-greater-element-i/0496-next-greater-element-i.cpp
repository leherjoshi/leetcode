class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            int idx = -1;

            // Find the element in nums2
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == nums1[i]) {
                    idx = j;
                    break;
                }
            }

            int greater = -1;

            // Search to the right
            for (int j = idx + 1; j < nums2.size(); j++) {
                if (nums2[j] > nums1[i]) {
                    greater = nums2[j];
                    break;
                }
            }

            ans.push_back(greater);
        }

        return ans;
    }
};