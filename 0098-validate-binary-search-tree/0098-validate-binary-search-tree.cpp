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
    bool helper(TreeNode* root, TreeNode* left, TreeNode* right) {
        if (root == nullptr)
            return true;

        // check BST property using boundary nodes
        if (left != nullptr && root->val <= left->val)
            return false;
        if (right != nullptr && root->val >= right->val)
            return false;

        // recursively check left and right subtrees
        return helper(root->left, left, root) && 
               helper(root->right, root, right);
    }

    bool isValidBST(TreeNode* root) {
        // initially, no boundaries exist → pass nullptr
        return helper(root, NULL, NULL);
    }
};
