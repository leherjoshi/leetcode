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
    vector<int>res;
TreeNode* inorder(TreeNode*root){
    if(root==nullptr){
        return nullptr;
    }
    root->left=inorder(root->left);
    res.push_back(root->val);
    root->right=inorder(root->right);
    return root;

}
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
       return res;
    }
};