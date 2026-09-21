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
    int mxdiff(TreeNode*root,int mn,int mx){
        if(!root)return mx-mn;

         mx=max(root->val,mx);
         mn=min(root->val,mn);

        return max(mxdiff(root->left,mn,mx),mxdiff(root->right,mn,mx));
    }
    int maxAncestorDiff(TreeNode* root) {
        
        return mxdiff(root,INT_MAX,INT_MIN);
    }
};