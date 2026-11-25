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
   int dfshei(TreeNode*root){
        if (root==NULL) return 0;


        int lefth=dfshei(root->left);


        if(lefth==-1) return -1;


        int refth=dfshei(root->right);


        if(refth==-1) return -1;

        if (abs(lefth - refth) > 1)  
            return -1;


        return max(lefth,refth)+1;
    }
    bool isBalanced(TreeNode* root) {
        return dfshei(root)!=-1;
    }
};