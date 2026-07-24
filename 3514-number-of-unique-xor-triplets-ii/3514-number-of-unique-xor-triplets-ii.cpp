class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> pairXor;

        // Store all unique XORs of pairs (i <= j)
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<int> ans;

        // Combine each pair XOR with every element
        for (int xr : pairXor) {
            for (int num : nums) {
                ans.insert(xr ^ num);
            }
        }

        return ans.size();
    }
};