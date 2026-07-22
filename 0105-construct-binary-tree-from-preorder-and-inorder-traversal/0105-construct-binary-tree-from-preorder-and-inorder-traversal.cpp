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
    unordered_map<int, int> mp;
   
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < size(inorder); i++) mp[inorder[i]] = i;
        int n = size(inorder), postIdx = 0;
        return build(inorder, preorder, 0, n-1, postIdx);
    }


    TreeNode* build(vector<int>& in, vector<int>& post, int inStart, int inEnd, int& postIdx) {
        if(inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(post[postIdx++]);
        int inIdx = mp[root -> val];
        root -> left  = build(in, post, inStart, inIdx-1, postIdx);
        root -> right = build(in, post, inIdx+1, inEnd, postIdx);
        
        return root;
 
    }
};