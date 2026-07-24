/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<int> nums;

void inorder(TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    nums.push_back(root->val);
    inorder(root->right);
}
    bool findTarget(TreeNode* root, int target) {
         inorder(root);
         unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            if (mp.find(need) != mp.end()) {
                return true;
            }

            mp[nums[i]] = i;
        }

        return false;
    }
};