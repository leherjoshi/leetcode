/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode *ans = nullptr;
        Tree(cloned,target,ans);
        return ans;
    }

    void Tree(TreeNode *cloned, TreeNode *target, TreeNode* &ans){
        if(cloned == nullptr) return;
        Tree(cloned->left,target,ans);
        if(cloned->val == target->val) ans = cloned; 
        Tree(cloned->right,target,ans);
    }
};